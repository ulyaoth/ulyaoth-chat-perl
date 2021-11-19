#!/usr/bin/perl

@font = split(/\s+/, $DATA{'msg'});

if(@font[1] == 1){

$fon = "Times";

}elsif(@font[1] == 2){

$fon = "Arial";

}elsif(@font[1] == 3){

$fon = "Copperplate Gothic Bold";

}elsif(@font[1] == 4){

$fon = "Impact";

}elsif(@font[1] == 5){

$fon = "Lucida Sans";

}elsif(@font[1] == 6){

$fon = "Book Antiqua";

}elsif(@font[1] == 7){

$fon = "Courier New";

}elsif(@font[1] == 8){

$fon = "Verdana";

}elsif(@font[1] == 9){

$fon = "Arial Narrow";

}elsif(@font[1] == 10){

$fon = "Comic Sans MS";

}elsif(@font[1] == 11){

$fon = "Calisto MT";

}elsif(@font[1] == 12){

$fon = "Garamond";

}elsif(@font[1] == 13){

$fon = "Tohama";

}elsif(@font[1] == 14){

$fon = "Microsoft Sans Serif";

}elsif(@font[1] == 15){

$fon = "Terminal";

}


if(!$fon){

dbmopen(%USER,"$root/online/users/$DATA{'n'}.db",0777);

undef $USER{'nfont'};

dbmclose(%USER);

$errors = " Nickname font type unset. To set font type again click on desired type below:<br>\n<b> <a href=\"$location?n=$DATA{'n'}&id=$DATA{'id'}&room=$room&msg=/nfont+1\"><font face=\"Times\">Times</a></font> || <a href=\"$location?n=$DATA{'n'}&id=$DATA{'id'}&room=$room&msg=/nfont+2\"><font face=\"Arial\">Arial</a></font> || <a href=\"$location?n=$DATA{'n'}&id=$DATA{'id'}&room=$room&msg=/nfont+3\"><font face=\"Copperplate Gothic Bold\">Copperplate Gothic Bold</a></font> ||  <a href=\"$location?n=$DATA{'n'}&id=$DATA{'id'}&room=$room&msg=/nfont+4\"><font face=\"Impact\">Impact</a></font> ||  <a href=\"$location?n=$DATA{'n'}&id=$DATA{'id'}&room=$room&msg=/nfont+5\"><font face=\"Lucida Sans\">Lucida Sans</a></font> ||  <a href=\"$location?n=$DATA{'n'}&id=$DATA{'id'}&room=$room&msg=/nfont+6\"><font face=\"Book Antiqua\">Book Antiqua</a></font> || <a href=\"$location?n=$DATA{'n'}&id=$DATA{'id'}&room=$room&msg=/nfont+7\"><font face=\"Courier New\">Courier New</a></font> || <a href=\"$location?n=$DATA{'n'}&id=$DATA{'id'}&room=$room&msg=/nfont+8\"><font face=\"Verdana\">Verdana</a></font> || <a href=\"$location?n=$DATA{'n'}&id=$DATA{'id'}&room=$room&msg=/nfont+9\"><font face=\"Arial Narrow\">Arial Narrow</a></font> || <a href=\"$location?n=$DATA{'n'}&id=$DATA{'id'}&room=$room&msg=/nfont+10\"><font face=\"Comic Sans MS\">Comic Sans MS</a></font> || <a href=\"$location?n=$DATA{'n'}&id=$DATA{'id'}&room=$room&msg=/nfont+11\"><font face=\"Calisto MT\">Calisto MT</a></font> || <a href=\"$location?n=$DATA{'n'}&id=$DATA{'id'}&room=$room&msg=/nfont+12\"><font face=\"Garamond\">Garamond</a></font> || <a href=\"$location?n=$DATA{'n'}&id=$DATA{'id'}&room=$room&msg=/nfont+13\"><font face=\"Tahoma\">Tahoma</a></font> || <a href=\"$location?n=$DATA{'n'}&id=$DATA{'id'}&room=$room&msg=/nfont+14\"><font face=\"Microsoft Sans Serif\">Microsoft Sans Serif</a></font> || <a href=\"$location?n=$DATA{'n'}&id=$DATA{'id'}&room=$room&msg=/nfont+15\"><font face=\"Terminal\">Terminal</a></font> ||</b>";

return $errors;

exit;

}

dbmopen(%USER,"$root/online/users/$DATA{'n'}.db",0777);


$USER{'nfont'} = $fon;

dbmclose(%USER);

$errors = " Font nickname type set to <font face=\"$fon\"><b>$fon</b></font>.";

return $errors;

exit;