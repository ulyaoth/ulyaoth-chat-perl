#!/usr/bin/perl


$java = "<SCRIPT LANGUAGE=\"JavaScript\"><!-- hide

function m(n) {

document.forms[0].msg.value='m '+n+' ';

}


// --></SCRIPT></HEAD>\n";



$body = "<BODY $bgcolor $text onload=\"window.status='$version';if (window != top) {top.location.href='$location?n=$DATA{'n'}&room=$room&id=$id';};document.forms[0].msg.focus()\">\n";

$refresher = "<META HTTP-EQUIV=\"refresh\" CONTENT=\"300;URL=$location?n=$DATA{'n'}&room=$room&id=$DATA{'id'}\">\n";

$method = "<FORM METHOD=\"POST\" NAME=\"msg\" ACTION=\"$location#b\">\n";

return true;