# Runtime: 420 ms, faster than 57.44% of MySQL online submissions for Actors and Directors Who Cooperated At Least Three Times.
# Memory Usage: 0B, less than 100.00% of MySQL online submissions for Actors and Directors Who Cooperated At Least Three Times.

SELECT actor_id, director_id
FROM ActorDirector
GROUP BY actor_id, director_id
HAVING COUNT(*) >= 3