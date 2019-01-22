"""More examples of data definitions (classes).

Two kinds:

  - Structs (named tuples)
  - Enums

Each class should have a purpose statement, and maybe some doctests.
"""


from enum import Enum, auto
from typing import Optional
from lib230 import record


# Example 1: car share ride


@record
class Person:
    id:     int
    name:   str


# TODO
@record
class Location:
    pass


@record
class Ride:
    passenger:  Person
    driver:     Person
    start:      Location
    end:        Location


# Example 2: cardinal directions


class CardinalDirection(Enum):
    NORTH = auto()
    SOUTH = auto()
    EAST = auto()
    WEST = auto()


# Example 3: flower plants


class SunPreference(Enum):
    SHADE = auto()
    PARTIAL = auto()
    FULL = auto()


@record
class FloweringPlant:
    common_name:    str
    max_height:     float
    sun_preference: SunPreference


# Example 4: electronic medical records


@record
class BloodLipids:
    hdl_cholesterol: float
    ldl_cholesterol: float
    triglycerides:   float


@record
class BloodPressure:
    systolic:        float
    diastolic:       float


@record
class Vitals:
    blood_pressure:  BloodPressure
    body_tempature:  float
    heart_rate:      int
    breath_rate:     int


class Sex(Enum):
    FEMALE = auto()
    MALE = auto()
    INTER = auto()


@record
class Biometrics:
    height:         float
    weight:         float
    age:            float
    sex:            Sex


@record
class MedicalRecord:
    id:             int
    name:           str
    biometrics:     Biometrics
    vitals:         Vitals
    blood_lipids:   Optional[BloodLipids]


