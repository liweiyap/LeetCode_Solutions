# Runtime: 1018 ms, faster than 90.97% of MySQL online submissions for Sales Person.
# Memory Usage: 0B, less than 100.00% of MySQL online submissions for Sales Person.

SELECT name
FROM SalesPerson a
WHERE a.sales_id NOT IN
(
    SELECT Orders.sales_id
    FROM Company
    INNER JOIN Orders
    ON Company.com_id = Orders.com_id
    WHERE Company.name = "RED"
)