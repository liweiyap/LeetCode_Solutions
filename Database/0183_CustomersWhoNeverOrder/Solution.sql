# Runtime: 351 ms, faster than 59.22% of MySQL online submissions for Customers Who Never Order.
# Memory Usage: 0B, less than 100.00% of MySQL online submissions for Customers Who Never Order.

SELECT Name AS Customers
FROM Customers
LEFT JOIN Orders ON Customers.Id = Orders.CustomerId
WHERE Orders.CustomerId IS NULL;
