# Runtime: 164 ms, faster than 87.48% of MySQL online submissions for Exchange Seats.
# Memory Usage: 0B, less than 100.00% of MySQL online submissions for Exchange Seats.

SELECT (CASE WHEN new.id = (SELECT MAX(id) FROM seat) AND new.id MOD 2 = 1 THEN new.id
             WHEN new.id MOD 2 = 1 THEN new.id + 1
             WHEN new.id MOD 2 = 0 THEN new.id - 1
        END) AS id,
        new.student
FROM seat new
INNER JOIN seat old
ON new.id = old.id
ORDER BY id;
