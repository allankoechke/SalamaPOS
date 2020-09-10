BEGIN TRANSACTION;
INSERT INTO "product"(barcode,product_name,product_unit,product_bp,product_sp,type_id,product_company) VALUES (:barcode,:product_name,:product_unit,:product_bp,:product_sp,:type_id,:product_company)";
INSERT INTO "stock"(barcode,stock_qty,last_update) VALUES (:barcode,:stock_qty,:last_update);
COMMIT;
