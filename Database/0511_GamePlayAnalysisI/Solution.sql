# Runtime: 698 ms, faster than 43.83% of MySQL online submissions for Game Play Analysis I.
# Memory Usage: 0B, less than 100.00% of MySQL online submissions for Game Play Analysis I.

SELECT player_id, MIN(event_date) As first_login
FROM Activity
GROUP BY player_id