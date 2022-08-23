# Runtime: 430 ms, faster than 86.64% of MySQL online submissions for Find Customer Referee.
# Memory Usage: 0B, less than 100.00% of MySQL online submissions for Find Customer Referee.

SELECT name
FROM Customer
WHERE referee_id IS null OR referee_id != 2