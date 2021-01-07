LEKY = [101,102,103,111,112,113,121,122,201,202,203,301,302,303,311,321,601,602,603];
function generateNew(Lekarna){
    return(
    "("+ Lekarna + ", " + 
LEKY[Math.round(Math.random()*LEKY.length)] + ", " + 
Math.round(Math.random()*200) + "),\r\n"
);
}
generated = "";
for(i = 1; i<= 12; i++){
    for(j = 1; j<4; j++){
    generated += generateNew(i)
}
}
//[id],[code],[id_user],[id_doctor],[id_medicament],[id_pharmacy],[publication_date],[pick_up_date],[description]
// Recepty

LEKY = [101,102,103,111,112,113,121,122,201,202,203,301,302,303,311,321,601,602,603];
function generateNewRecipe(id){    
    createDate = -1*Math.floor(Math.random()*600);
    pickedUp = (Math.random()*10 > 8) ? "DATEADD(day, "+(createDate + Math.floor(Math.random()*20))+",GETDATE())": "NULL"
    return(
    "("+ id + ", " + 
    (Math.floor(Math.random()*999999)+1) + ", " + 
    (Math.floor(Math.random()*20)+1) + ", " + 
    (Math.floor(Math.random()*10)+1) + ", " + 
    LEKY[Math.floor(Math.random()*LEKY.length)] + ", " + 
    (Math.floor(Math.random()*12)+1) + ", " + 
    "DATEADD(day, "+createDate+",GETDATE())" + 
    ", " + pickedUp + 
    "),\r\n"
);
}
generated = "";
for(i = 1; i<= 40; i++){
    generated += generateNewRecipe(i)

}