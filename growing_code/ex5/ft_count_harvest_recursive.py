def ft_count_harvest_recursive() -> None:
    days = int(input("Days until harvest: "))

    def countdown(day: int, count: int) -> None:
        if day == 0:
            print("Harvest time!")
        else:
            print(f"Day {count}")
            countdown(day - 1, count + 1)
    countdown(days, 1)
