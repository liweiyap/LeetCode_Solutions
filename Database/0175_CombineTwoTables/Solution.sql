# Runtime: 264 ms, faster than 63.38% of MySQL online submissions for Combine Two Tables.
# Memory Usage: 0B, less than 100.00% of MySQL online submissions for Combine Two Tables.

SELECT Person.FirstName, Person.LastName, Address.City, Address.State
FROM Person
LEFT JOIN Address
ON Person.PersonId = Address.PersonId;
