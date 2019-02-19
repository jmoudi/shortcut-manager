
class CSVMap extends Map {
    constructor(csvText){
        super();
        this.separator = ";";
        this.column = {};

        this.columns = { };
        this.rows = { };
        const lines = csvText.split("\n").filter(line => line.includes(",") && line.length > 3);
        for (let i = 0; i < lines.length; i++){
            if (lines[i].length > 4){ console.log(`Processing Line nr:`, i, lines[i]);
                this.rows[i] = lines[i].split(",").map(param => param.trim()); 
                console.log(``, i, this.rows[i]);
            }
        }
        const columnNames = this.rows[0];
        for (let i = 0; i < columnNames.length; i++){
            this.columns[i] = columnNames[i];
            this.set(columnNames[i], []);
            Object.defineProperty(this, columnNames[i], {
                get: function(){ return this.get(columnNames[i]).join(this.separator); }
            })
        }
        for (let value of Object.values(this.rows)){ console.log(``,)
            for (let i = 0; i < value.length; i++){
                this.get(columnNames[i]).push(value[i]); }
        }
        
    }

     
};
    let d = new CSVMap(`
    Key , Command , Param , Options
    !s , enter , 罗马鞋 OR 罗马凉鞋 OR 罗马女鞋 OR 罗马高跟鞋 OR 罗马粗跟鞋 OR 罗马中跟鞋 , 
    !+s , paste , 罗马鞋 OR 罗马凉鞋 OR 罗马女鞋 OR 罗马高跟鞋 OR 罗马粗跟鞋 OR 罗马中跟鞋 , 
    !^s , paste , 罗马鞋 OR 罗马凉鞋 OR 罗马女鞋 OR 罗马高跟鞋 , 
    !x , find , 罗马 , 
    !+x , find , 单鞋 , 
    !^x , find , 鱼嘴 , 
    !<^>x , find , 旗袍 , 
    !y , find , 羅馬 , 
    !+y , find , 單鞋 , 
    !^y , find , 高跟 , 
    !f , enter , 罗马 , 
    !+f , paste , 罗马 , 
    !^f , enter , 罗马鞋 , 
    !g , enter , 罗马 凉鞋 , 
    !+g , paste , 罗马 凉鞋 , 
    !^g , paste , 罗马 鞋 , 
    !h , enter , 羅馬 , `);
     console.log(d)
 
class CSVMap extends Map {
    constructor(csvText){
        super();
        this.separator = ";";
        this.column = {};

        this.columns = { };
        this.rows = { };
        const lines = csvText.split("\n").filter(line => line.includes(",") && line.length > 3);
        for (let i = 0; i < lines.length; i++){
            if (lines[i].length > 4){ console.log(`Processing Line nr:`, i, lines[i]);
                this.rows[i] = lines[i].split(",").map(param => param.trim()); 
                console.log(``, i, this.rows[i]);
            }
        }
        const columnNames = this.rows[0];
        for (let i = 0; i < columnNames.length; i++){
            this.columns[i] = columnNames[i];
            this.set(columnNames[i], []);
            Object.defineProperty(this, columnNames[i], {
                get: function(){ return this.get(columnNames[i]).join(this.separator); }
            })
        }
        for (let value of Object.values(this.rows)){ console.log(``,)
            for (let i = 0; i < value.length; i++){
                this.get(columnNames[i]).push(value[i]); }
        }
        
    }

     
};
 