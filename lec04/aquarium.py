# enables methods to return their own class type:
from __future__ import annotations

from typing import List, Optional
from enum import Enum, auto
from lib230 import record, Factory


class WaterType(Enum):
    """Represents the type of water that a fish requires."""
    FRESH = auto()
    BRACKISH = auto()
    SALT = auto()


@record
class Fish:
    """Represents a pet fish.

    >>> f = Fish('name', 5, 10)
    >>> f.weight_kg
    5
    >>> f.age_days
    10
    >>> f.species
    'unknown'
    """

    name:       str
    weight_kg:  float
    age_days:   int = 0
    species:    str = 'unknown'
    water_type: WaterType = WaterType.FRESH

    def increment_age(self) -> None:
        """Adds one day to the age of this fish.

        >>> fish = Fish('Cleo', 0.03, 18, 'goldfish', WaterType.FRESH)
        >>> fish.age_days
        18
        >>> fish.increment_age()
        >>> fish.age_days
        19
        >>> fish.increment_age()
        >>> fish.age_days
        20
        """
        self.age_days += 1


@record
class Aquarium2:
    """Represents an aquarium of two fish."""

    fish1: Fish
    fish2: Fish

    def increment_all_ages(self) -> None:
        """Adds one day to the age of each fish.

        >>> aq = Aquarium2(Fish('Cleo', 0.03, 18, 'goldfish', WaterType.FRESH),
        ...                Fish('Larry', 150, 700, 'shark', WaterType.SALT))
        >>> (aq.fish1.age_days, aq.fish2.age_days)
        (18, 700)
        >>> aq.increment_all_ages()
        >>> (aq.fish1.age_days, aq.fish2.age_days)
        (19, 701)
        """
        self.fish1.increment_age()
        self.fish2.increment_age()

    def heaviest_fish(self) -> Fish:
        """Returns whichever fish is heaviest; ties go to fish1.

        >>> Aquarium2(Fish('dory', 5), Fish('nemo', 10)).heaviest_fish().name
        'nemo'
        >>> Aquarium2(Fish('dory', 15), Fish('nemo', 10)).heaviest_fish().name
        'dory'
        >>> Aquarium2(Fish('dory', 10), Fish('nemo', 10)).heaviest_fish().name
        'dory'
        """
        if self.fish1.weight_kg >= self.fish2.weight_kg:
            return self.fish1
        else:
            return self.fish2

    def average_weight(self) -> float:
        """Returns the average fish weight.

        >>> Aquarium2(Fish('dory', 5), Fish('nemo', 10)).average_weight()
        7.5
        >>> Aquarium2(Fish('dory', 15), Fish('nemo', 10)).average_weight()
        12.5
        """
        return (self.fish1.weight_kg + self.fish2.weight_kg) / 2


@record
class Aquarium3:
    """Represents an aquarium of three fish."""

    fish1: Fish
    fish2: Fish
    fish3: Fish

    def increment_all_ages(self) -> None:
        """Adds one day to the age of each fish.

        >>> aq = Aquarium3(Fish('Cleo', 0.03, 18, 'goldfish', WaterType.FRESH),
        ...                Fish('Larry', 150, 700, 'shark', WaterType.SALT),
        ...                Fish('Otto', 500, 45, 'goldfish?', WaterType.FRESH))
        >>> (aq.fish1.age_days, aq.fish2.age_days, aq.fish3.age_days)
        (18, 700, 45)
        >>> aq.increment_all_ages()
        >>> (aq.fish1.age_days, aq.fish2.age_days, aq.fish3.age_days)
        (19, 701, 46)
        """
        self.fish1.increment_age()
        self.fish2.increment_age()
        self.fish3.increment_age()

    def heaviest_fish(self) -> Fish:
        """Returns whichever fish is heaviest. Ties go to earliest."""
        def max_fish(f1: Fish, f2: Fish) -> Fish:
            return Aquarium2(f1, f2).heaviest_fish()
        return max_fish(self.fish1, max_fish(self.fish2, self.fish3))

    def average_weight(self) -> float:
        """Returns the average fish weight."""
        return (self.fish1.weight_kg
                + self.fish2.weight_kg
                + self.fish3.weight_kg) / 3


@record
class Aquarium:
    """An aquarium of any number of fish.

    >>> aq = Aquarium()
    >>> aq.append(Fish('A', 10))
    >>> aq.append(Fish('B', 8))
    >>> aq.append(Fish('C', 6))
    >>> aq.append(Fish('D', 10))
    >>> len(aq.all_fish)
    4
    >>> aq.all_fish[0].weight_kg
    10
    """

    all_fish: List[Fish] = Factory(list)

    def append(self, fish: Fish) -> None:
        """Adds a new fish to the aquarium

        >>> aq = Aquarium()
        >>> len(aq.all_fish)
        0
        >>> aq.append(Fish('A', 1))
        >>> aq.append(Fish('B', 2))
        >>> len(aq.all_fish)
        2
        >>> aq.all_fish[1].name
        'B'
        """
        self.all_fish.append(fish)

    def increment_all_ages(self) -> None:
        """Increases the age of every fish in the aquarium by
        one day.

        >>> aq = Aquarium([ Fish('A', 1, 10),
        ...                 Fish('B', 2, 20),
        ...                 Fish('C', 3, 30) ])
        >>> aq.increment_all_ages()
        >>> aq.all_fish[0].age_days
        11
        """
        for fish in self.all_fish:
            fish.increment_age()

    def heaviest_fish(self) -> Optional[Fish]:
        """Finds the heaviest fish, if any.

        >>> aq = Aquarium()
        >>> aq.heaviest_fish()
        >>> aq.append(Fish('A', 10))
        >>> aq.heaviest_fish().name
        'A'
        >>> aq.append(Fish('B', 15))
        >>> aq.heaviest_fish().name
        'B'
        >>> aq.append(Fish('C', 15))
        >>> aq.heaviest_fish().name
        'B'
        """
        best = None
        for fish in self.all_fish:
            if best is None or fish.weight_kg > best.weight_kg:
                best = fish
        return best

    # average_weight?
    # all_heaviest_fish?

