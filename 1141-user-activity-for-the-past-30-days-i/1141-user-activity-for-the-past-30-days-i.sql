# Write your MySQL query statement below
SELECT DISTINCT activity_date AS day , COUNT(DISTINCT user_id) AS active_users
FROM Activity 
WHERE activity_date BETWEEN
    DATE_SUB('2019-07-28' , INTERVAL 1 MONTH) AND '2019-07-28'
GROUP BY activity_date
ORDER BY activity_date 