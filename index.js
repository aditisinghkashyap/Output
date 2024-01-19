
let i  = 0;
let cost = [20 , 40 , 50] ;
let arr = [] ;
let totalit = 0 ;
let totalct = 0 ;
let pr= "A" ;
while( i < 3 ) {
    let qty = prompt(` Enter the quantity of product ${pr}:`);
    arr.push({p:pr , q : qty}) ;
    pr = String.fromCharCode(pr.charCodeAt(0) + 1) 
    totalit += parseInt(qty) ; 
    totalct += ( qty * cost[ i ] ) ;
    i++;
}

let dis1 = 0 ;
let dis2 = 0 ;
let dis3 = 0 ;
let dis4 = 0 ;
let dis1name = "flat_10" ;
let dis2name = "bulk_5_discount" ;
let dis3name = "bulk_10_discount" ;
let dis4name = "tiered_50_discount" ;

if( totalct > 200 ) {
    dis1 = 10 ;
}
i = 0 ;
while( i < 3 ) {
    if( arr[ i ].q > 10 && dis2 != 0 ){
        dis2 = totalct * 0.05 ;
    }
    if( arr[ i ].q > 20 && dis3 == 0  ){
        dis3 = totalct * 0.1 ;
    }
    if( totalit > 30 && arr[ i ].q > 15 ) {
        dis4 += ( 0.5 *  ((arr[ i ].q) - 15 ) ) ;
    }
    i++;
}
let finaldisname = "" ;
let maxi = Math.max( dis1 , dis2 , dis3 , dis4 ) ;
if(maxi == dis1 ) {
finaldisname = dis1name ;
}
if(maxi == dis2 ) {
    finaldisname = dis2name ;
}
if(maxi == dis3 ) {
    finaldisname = dis3name ;
}
if(maxi == dis4 ) {
    finaldisname = dis4name ;
}
if( maxi == 0 ) {
    finaldisname = "No Discount Applicable"
}
let ques = prompt("Do you want to wrap this product ? (Y/N) :") ;
let gift = 0;
if( ques == "Y" ) {
    totalct++;
    gift++;
}
console.log(totalit) ;
let shipping = (totalit / 10 ) *  5 ;
i = 0 ;
while( i < 3 ) {
console.log(`${arr[ i ].p}  ${arr[ i ].q}  ${arr[ i ].q * cost[ i ]} `) ;
i++;
}
console.log(`Total Cost :${totalct}`);
console.log(`Final Discount :${finaldisname} ${maxi}`) ;
console.log(`Shipping :${shipping} Gift Wrap Fee : ${gift} `  );
console.log(`Total Amount: ${( totalct - maxi + shipping )}` ) ;