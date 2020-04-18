# Runtime: 187 ms, faster than 92.63% of MySQL online submissions for Trips and Users.
# Memory Usage: 0B, less than 100.00% of MySQL online submissions for Trips and Users.

SELECT Request_at AS Day,
       ROUND(SUM(CASE WHEN STATUS NOT IN ("completed") THEN 1 ELSE 0 END)/COUNT(Request_at),2) AS "Cancellation Rate"
FROM Trips
INNER JOIN Users u
ON Client_Id = u.Users_Id
INNER JOIN Users v
ON Driver_Id = v.Users_Id
WHERE u.Banned = "No" AND v.Banned = "No"
AND Request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY Request_at;
