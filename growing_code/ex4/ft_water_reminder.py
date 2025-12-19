def ft_water_reminder() -> None:
    last_watered = input("Days since last watering: ")
    if int(last_watered) > 2:
        print("Water the plants!")
    else:
        print("Plants are fine.")
