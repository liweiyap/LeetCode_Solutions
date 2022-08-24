# Runtime: 453 ms, faster than 75.70% of MySQL online submissions for Customer Placing the Largest Number of Orders.
# Memory Usage: 0B, less than 100.00% of MySQL online submissions for Customer Placing the Largest Number of Orders.

SELECT customer_number
FROM
(
    SELECT customer_number, COUNT(customer_number) AS customer_orders
    FROM Orders
    GROUP BY customer_number
    ORDER BY customer_orders DESC
    LIMIT 1
) CustomerOrders