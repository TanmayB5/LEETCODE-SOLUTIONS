# Write your MySQL query statement below
-- SELECT DISTINCT p.product_id , AVG((p.price * u.units)) AS average_price 
-- FROM Prices p LEFT JOIN UnitsSold u 
-- ON u.purchase_date BETWEEN 
--     p.start_date AND p.end_date
-- GROUP BY product_id

SELECT 
    p.product_id,
    ROUND(IFNULL(SUM(p.price * u.units) / SUM(u.units), 0) , 2) AS average_price
FROM Prices p
LEFT JOIN UnitsSold u
    ON p.product_id = u.product_id
   AND u.purchase_date BETWEEN p.start_date AND p.end_date
GROUP BY p.product_id;
