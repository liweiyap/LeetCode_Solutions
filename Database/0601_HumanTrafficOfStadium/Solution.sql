# Runtime: 217 ms, faster than 68.06% of MySQL online submissions for Human Traffic of Stadium.
# Memory Usage: 0B, less than 100.00% of MySQL online submissions for Human Traffic of Stadium.

SELECT DISTINCT(erste.id), erste.visit_date, erste.people
FROM stadium erste, stadium zweite, stadium dritte
WHERE ((erste.id + 1 = zweite.id AND erste.id + 2 = dritte.id) OR
       (erste.id - 1 = zweite.id AND erste.id + 1 = dritte.id) OR
       (erste.id - 2 = zweite.id AND erste.id - 1 = dritte.id))
AND erste.people >= 100 AND zweite.people >= 100 AND dritte.people >= 100
ORDER BY id;
