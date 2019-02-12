from typing import Callable, Iterator, List, Optional

from lib230 import record


@record(repr=False)
class Employee:
    name:   str
    id:     int
    wage:   int = 1500
    mgr_id: Optional[int] = None

    # passing repr=False to @record above lets us define our own __repr__:
    def __repr__(self) -> str:
        """Converts an `Employee` object to a string for debugging.

        >>> Employee('Hans', 2, wage=1800)
        Hans(2)
        >>> Employee('Franz', 3, mgr_id=2)
        Franz(3)
        """
        return '{}({})'.format(self.name, self.id)


@record(init=False)
class EmployeeRoll:
    _employees: List[Employee]
    # Invariant: No two employees have the same ID

    # passing init=False to @record above lets us define our own constructor:
    def __init__(self) -> None:
        """Constructs an empty `EmployeeRoll`.

        >>> EmployeeRoll()
        EmployeeRoll(_employees=[])
        """
        self._employees = []

    def __iter__(self) -> Iterator[Employee]:
        """Lets us write `for` loops over `self`.

        >>> roll = EmployeeRoll()
        >>> roll.append(Employee('Alice', 2))
        >>> roll.append(Employee('Bob', 4))
        >>> for e in roll:
        ...     print(e)
        Alice(2)
        Bob(4)
        """
        return self._employees.__iter__()

    def append(self, employee: Employee) -> None:
        """Adds an employee to the list of employees."""
        self._employees.append(employee)

    def find_by_id(self, id: int) -> Optional[Employee]:
        """Finds the employee with the given id, if any.

        >>> roll = EmployeeRoll()
        >>> roll.append(Employee('Alice', 2))
        >>> roll.append(Employee('Bob', 4))
        >>> roll.find_by_id(2)
        Alice(2)
        >>> roll.find_by_id(3)
        >>> roll.find_by_id(4)
        Bob(4)
        """
        pass  # TODO

    def find_by_mgr_id(self, mgr_id: int) -> List[Employee]:
        """Finds all employees with the given manager id.

        >>> roll = EmployeeRoll()
        >>> roll.append(Employee('Alice', 2, mgr_id=1))
        >>> roll.append(Employee('Bob', 4, mgr_id=2))
        >>> roll.append(Employee('Carol', 6, mgr_id=2))
        >>> roll.find_by_mgr_id(1)
        [Alice(2)]
        >>> roll.find_by_mgr_id(2)
        [Bob(4), Carol(6)]
        >>> roll.find_by_mgr_id(3)
        []
        """
        pass  # TODO

    def all_names(self) -> List[str]:
        """Returns a list of all employees' names.

        >>> roll = EmployeeRoll()
        >>> roll.append(Employee('Alice', 2))
        >>> roll.append(Employee('Bob', 4))
        >>> roll.append(Employee('Carol', 6))
        >>> roll.all_names()
        ['Alice', 'Bob', 'Carol']
        """
        pass  # TODO

    def all_mgr_ids(self) -> List[int]:
        """Finds the IDs of all managers (not repeated).

        >>> roll = EmployeeRoll()
        >>> roll.all_mgr_ids()
        []
        >>> roll.append(Employee('Alice', 2, mgr_id=1))
        >>> roll.append(Employee('Bob', 4, mgr_id=2))
        >>> roll.append(Employee('Carol', 6, mgr_id=2))
        >>> roll.all_mgr_ids()
        [1, 2]
        """
        result: List[int] = []
        for e in self._employees:
            if e.mgr_id is not None and e.mgr_id not in result:
                result.append(e.mgr_id)
        pass  # TODO

    def total_payroll(self) -> int:
        """Returns the sum of all employees' wages.

        >>> roll = EmployeeRoll()
        >>> roll.total_payroll()
        0
        >>> roll.append(Employee('Alice', 2, wage=1000))
        >>> roll.append(Employee('Bob', 4, wage=2000))
        >>> roll.append(Employee('Carol', 6, wage=3000))
        >>> roll.total_payroll()
        6000
        """
        pass  # TODO

    def raise_all(self, factor: float) -> None:
        """Multiplies everyone's wage by the given factor.

        >>> roll = EmployeeRoll()
        >>> roll.append(Employee('Alice', 2, wage=1000))
        >>> roll.append(Employee('Bob', 4, wage=2000))
        >>> roll.append(Employee('Carol', 6, wage=3000))
        >>> roll.total_payroll()
        6000
        >>> roll.raise_all(1.2)
        >>> roll.total_payroll()
        7200
        >>> roll.find_by_id(6).wage
        3600
        """
        pass  # TODO

    def raise_by_mgr_id(self, mgr_id: int, factor: float) -> None:
        """Multiplies the wage of employees whose manager is mgr_id by
        factor.

        >>> roll = EmployeeRoll()
        >>> roll.append(Employee('Alice', 2, wage=1000, mgr_id=1))
        >>> roll.append(Employee('Bob', 4, wage=2000, mgr_id=2))
        >>> roll.append(Employee('Carol', 6, wage=3000, mgr_id=2))
        >>> roll.raise_by_mgr_id(2, 1.2)
        >>> [employee.wage for employee in roll]
        [1000, 2400, 3600]
        >>> roll.raise_by_mgr_id(1, 1.5)
        >>> [employee.wage for employee in roll]
        [1500, 2400, 3600]
        """
        pass  # TODO

    def raise_if(self, pred: Callable[[Employee], bool], factor: float) -> None:
        """Multiplies the wage of employees satisfying the predicate by
        the given factor.

        >>> roll = EmployeeRoll()
        >>> roll.append(Employee('Alice', 2, wage=1000, mgr_id=1))
        >>> roll.append(Employee('Bob', 4, wage=2000, mgr_id=2))
        >>> roll.append(Employee('Carol', 6, wage=3000, mgr_id=2))
        >>> roll.raise_if(lambda e: e.mgr_id == 2, 1.2)
        >>> [employee.wage for employee in roll]
        [1000, 2400, 3600]
        >>> roll.raise_if(lambda e: e.wage < 2000, 3)
        >>> [employee.wage for employee in roll]
        [3000, 2400, 3600]
        """
        pass  # TODO

    def find_root_mgr(self, id: int) -> Optional[Employee]:
        """Finds the uppermost manager reachable from the given employee id.

        >>> roll = EmployeeRoll()
        >>> roll.append(Employee('Alice', 1))
        >>> roll.append(Employee('Bob', 2, mgr_id=1))
        >>> roll.append(Employee('Carol', 3, mgr_id=1))
        >>> roll.append(Employee('Dave', 4, mgr_id=3))
        >>> roll.find_root_mgr(0)
        >>> roll.find_root_mgr(1)
        Alice(1)
        >>> roll.find_root_mgr(2)
        Alice(1)
        >>> roll.find_root_mgr(3)
        Alice(1)
        >>> roll.find_root_mgr(4)
        Alice(1)
        """
        pass  # TODO

