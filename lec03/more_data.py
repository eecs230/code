"""More examples of data definitions.

Two kinds:

  - Structs (named tuples)
  - Enums
"""


from enum import Enum, auto
from typing import NamedTuple, Optional


# Example 1: car share ride


class Person(NamedTuple):
    id:     int
    name:   str


# TODO
class Location(NamedTuple):
    pass


class Ride(NamedTuple):
    passenger:  Person
    driver:     Person
    start:      Location
    end:        Location


# Example 2: cardinal directions


class CardinalDirectin(Enum):
    NORTH = auto()
    SOUTH = auto()
    EAST = auto()
    WEST = auto()


# Example 3: flower plants


class SunPreference(Enum):
    SHADE = auto()
    PARTIAL = auto()
    FULL = auto()


class FloweringPlant(NamedTuple):
    common_name:    str
    max_height:     float
    sun_preference: SunPreference


# Example 4: electronic medical records


class BloodLipids(NamedTuple):
    hdl_cholesterol: float
    ldl_cholesterol: float
    triglycerides:   float


class BloodPressure(NamedTuple):
    systolic:        float
    diastolic:       float


class Vitals(NamedTuple):
    blood_pressure:  BloodPressure
    body_tempature:  float
    heart_rate:      int
    breath_rate:     int


class Sex(Enum):
    FEMALE = auto()
    MALE = auto()
    INTER = auto()


class Biometrics(NamedTuple):
    height:         float
    weight:         float
    age:            float
    sex:            Sex


class MedicalRecord(NamedTuple):
    id:             int
    name:           str
    biometrics:     Biometrics
    vitals:         Vitals
    blood_lipids:   Optional[BloodLipids]


