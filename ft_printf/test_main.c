/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caualves@student.42.rio <caualves@stude    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:13:37 by caualves@st       #+#    #+#             */
/*   Updated: 2025/12/22 16:13:37 by caualves@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

static int test_count = 0;
static int pass_count = 0;

// Helper macro to create test functions
#define CREATE_TEST(name, fmt, ...) \
	static int test_##name(void) { \
		char std_buf[4096] = {0}, ft_buf[4096] = {0}; \
		int std_ret, ft_ret; \
		FILE *tmp1, *tmp2; \
		int saved_stdout = dup(1); \
		long size1, size2; \
		tmp1 = tmpfile(); \
		if (!tmp1) return (0); \
		dup2(fileno(tmp1), 1); \
		std_ret = printf(fmt, ##__VA_ARGS__); \
		fflush(stdout); \
		fseek(tmp1, 0, SEEK_END); \
		size1 = ftell(tmp1); \
		rewind(tmp1); \
		if (size1 > 0 && size1 < 4096) { \
			fread(std_buf, 1, size1, tmp1); \
			std_buf[size1] = '\0'; \
		} \
		fclose(tmp1); \
		tmp2 = tmpfile(); \
		if (!tmp2) { \
			dup2(saved_stdout, 1); \
			close(saved_stdout); \
			return (0); \
		} \
		dup2(fileno(tmp2), 1); \
		ft_ret = ft_printf(fmt, ##__VA_ARGS__); \
		fflush(stdout); \
		fseek(tmp2, 0, SEEK_END); \
		size2 = ftell(tmp2); \
		rewind(tmp2); \
		if (size2 > 0 && size2 < 4096) { \
			fread(ft_buf, 1, size2, tmp2); \
			ft_buf[size2] = '\0'; \
		} \
		fclose(tmp2); \
		dup2(saved_stdout, 1); \
		close(saved_stdout); \
		return (strcmp(std_buf, ft_buf) == 0 && std_ret == ft_ret); \
	}

CREATE_TEST(char_test, "%c", 'A')
CREATE_TEST(string_test, "%s", "test")
CREATE_TEST(pos_int, "%d", 42)
CREATE_TEST(neg_int, "%d", -42)
CREATE_TEST(int_i, "%i", 42)
CREATE_TEST(unsigned_test, "%u", 42U)
CREATE_TEST(hex_lower, "%x", 255)
CREATE_TEST(hex_upper, "%X", 255)
CREATE_TEST(percent, "%%")
CREATE_TEST(null_str, "%s", (char *)NULL)
CREATE_TEST(multiple, "Num: %d, Hex: %x, Char: %c", 42, 42, 'A')
CREATE_TEST(zeros, "Zero d: %d, u: %u, x: %x", 0, 0, 0)

static int test_pointer(void)
{
	char std_buf[4096] = {0}, ft_buf[4096] = {0};
	int std_ret, ft_ret;
	FILE *tmp1, *tmp2;
	int saved_stdout = dup(1);
	void *ptr = &test_pointer;
	long size1, size2;
	
	tmp1 = tmpfile();
	if (!tmp1)
	{
		dup2(saved_stdout, 1);
		close(saved_stdout);
		return (0);
	}
	dup2(fileno(tmp1), 1);
	std_ret = printf("%p", ptr);
	fflush(stdout);
	fseek(tmp1, 0, SEEK_END);
	size1 = ftell(tmp1);
	rewind(tmp1);
	if (size1 > 0 && size1 < 4096)
	{
		fread(std_buf, 1, size1, tmp1);
		std_buf[size1] = '\0';
	}
	fclose(tmp1);
	
	tmp2 = tmpfile();
	if (!tmp2)
	{
		dup2(saved_stdout, 1);
		close(saved_stdout);
		return (0);
	}
	dup2(fileno(tmp2), 1);
	ft_ret = ft_printf("%p", ptr);
	fflush(stdout);
	fseek(tmp2, 0, SEEK_END);
	size2 = ftell(tmp2);
	rewind(tmp2);
	if (size2 > 0 && size2 < 4096)
	{
		fread(ft_buf, 1, size2, tmp2);
		ft_buf[size2] = '\0';
	}
	fclose(tmp2);
	
	dup2(saved_stdout, 1);
	close(saved_stdout);
	
	return (strcmp(std_buf, ft_buf) == 0 && std_ret == ft_ret);
}

static void run_test(const char *test_name, int (*test_func)(void))
{
	int passed;
	
	test_count++;
	passed = test_func();
	if (passed)
		pass_count++;
	
	printf("│ %-40s │ %s │\n", test_name, passed ? " ✓ OK " : "✗ NOK");
}

int main(void)
{
	printf("┌──────────────────────────────────────────┬────────┐\n");
	printf("│ ft_printf Testing Protocol               │ Result │\n");
	printf("├──────────────────────────────────────────┼────────┤\n");
	
	run_test("%c (single character)", test_char_test);
	run_test("%s (string)", test_string_test);
	run_test("%d (positive integer)", test_pos_int);
	run_test("%d (negative integer)", test_neg_int);
	run_test("%i (integer)", test_int_i);
	run_test("%u (unsigned integer)", test_unsigned_test);
	run_test("%x (lowercase hex)", test_hex_lower);
	run_test("%X (uppercase hex)", test_hex_upper);
	run_test("%p (pointer)", test_pointer);
	run_test("%% (percent sign)", test_percent);
	run_test("%s (NULL pointer)", test_null_str);
	run_test("Multiple conversions", test_multiple);
	run_test("Zero values", test_zeros);
	
	printf("└──────────────────────────────────────────┴────────┘\n");
	printf("\nResults: %d/%d tests passed\n", pass_count, test_count);
	
	return (pass_count == test_count ? 0 : 1);
}
