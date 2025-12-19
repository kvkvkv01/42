def ft_seed_inventor(seed_type: str, quantity: int, unit: str) -> None:
    if unit == "packets":
        print(f"{seed_type.capitalize()}: {quantity} {unit} available")
    elif unit == "grams":
        print(f"{seed_type.capitalize()}: {quantity} {unit} total")
    elif unit == "area":
        print(f"{seed_type.capitalize()}: covers {quantity} square meters")
    else:
        print("Unknown unit type.")