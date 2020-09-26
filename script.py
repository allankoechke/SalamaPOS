import time, datetime

cat = {}

def currentMillisString():
    millis = int(round(time.time() * 1000))
    return f"{millis}"

def currentTimestamp():
    d = datetime.datetime.now()
    d = d.strftime("%Y-%m-%d %H:%M:%S+03")
    return d

def getId(barcode, category):
    if(len(cat) == 0):
        cat_id = barcode[-5:]
        cat[cat_id] = category
        return cat_id

    else:
        for key, val in cat.items():
            if val == category:
                return key

        cat_id = barcode[-5:]
        cat[cat_id] = category
        return cat_id



if __name__ == "__main__":
    # Read stock txt
    file = open("nstock.txt", "r")
    stok = open("stock.sql", "w")
    cat_ = open("type.sql", "w")
    prod = open("item.sql", "w")

    for line in file:
        # Create a new line with code
        line = line.strip("\n")
        arr = line.split("\t")

        id = getId(arr[0], arr[6])
        nline = "INSERT INTO product(barcode, product_name, product_unit, product_bp, product_sp, product_company, type_id) VALUES('" + arr[0] + "','" + arr[1] + "','" + arr[2] + "','" + arr[3] + "','" + arr[4] + "','" + arr[5] + "','" + id + "');\n"

        # write to stock
        _st = "INSERT INTO stock(barcode,stock_qty, last_update) VALUES ('" + arr[0] + "','0','" + currentTimestamp() + "');\n"
        stok.write(_st)

        # write to products
        prod.write(nline)

    for key, val in cat.items():
        _str = "INSERT INTO product_type(type_id, type_name) VALUES('" + key + "','" + val + "');\n"
        cat_.write(_str)

    cat_.close()
    file.close()
    prod.close()
    stok.close()