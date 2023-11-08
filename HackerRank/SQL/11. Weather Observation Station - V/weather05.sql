(SELECT * FROM (SELECT city, LENGTH(city) FROM station ORDER BY LENGTH(city) ASC, city ASC) WHERE rownum=1)
UNION
(SELECT * FROM (SELECT city, LENGTH(city) FROM station ORDER BY LENGTH(city) DESC, city ASC) WHERE rownum=1);