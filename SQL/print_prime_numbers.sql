SET @num:=1;
SET @mod:=1;

SELECT GROUP_CONCAT(NUM1 SEPARATOR '&')
FROM (SELECT @num:= @num + 1 AS NUM1
     FROM information_schema.tables t1, 
          information_schema.tables t2
     LIMIT 1000
     ) TMP
WHERE NOT EXISTS (SELECT *
                  FROM (SELECT @mod:= @mod + 1 AS NUM2
                        FROM information_schema.tables t1, 
                            information_schema.tables t2
                        LIMIT 1000
                        ) PRIME 
                  WHERE NUM1 % NUM2 = 0 AND
                        NUM2 < NUM1
                 )
