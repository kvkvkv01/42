def ft_count_harvest_iterative() -> None:
    days_until_harvest = input("Days until harvest: ")
    x = 1
    while int(days_until_harvest) > 0:
        print(f"Day {x}")
        days_until_harvest = str(int(days_until_harvest) - 1)
        x += 1
    print("Harvest time!")
