# Runtime: 721 ms, faster than 87.92% of MySQL online submissions for Delete Duplicate Emails.
# Memory Usage: 0B, less than 100.00% of MySQL online submissions for Delete Duplicate Emails.

DELETE
FROM Person
WHERE Id NOT IN
(
    SELECT FirstEntries.Id FROM (  # Avoid the error message "Can't specify target table for update in FROM clause"
        SELECT MIN(Id) AS Id
        FROM Person
        GROUP BY Email
    ) AS FirstEntries
);
