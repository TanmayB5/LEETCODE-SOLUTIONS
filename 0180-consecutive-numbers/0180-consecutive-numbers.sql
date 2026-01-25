# Write your MySQL query statement below
-- SELECT num AS ConsecutiveNums 
-- FROM Logs 
-- WHERE LAG(num) = num AND  LEAD(num) = num 

SELECT DISTINCT num AS ConsecutiveNums 
FROM (
    SELECT num,
    LAG(num) OVER(ORDER BY id) as prev,
    LEAD(num) OVER(ORDER BY id) as next
    FROM Logs
)t
WHERE num = prev
  AND num = next;