#!/usr/bin/perl





if ($command eq '/help'){





 print "Content-type: text/html\n\n";



 require "$root/inc/print_header.inc";







if($level >= 0){



print "<PRE>";





open(USERCOMMANDS,"$root/txt/usercommands.txt");



@usercommands = <USERCOMMANDS>;



close(USERCOMMANDS);

foreach $line(@usercommands){



print $line;





}







}





if($level >= $comm_rank){





open(COMMCOMMANDS,"$root/txt/commcommands.txt");



@commcommands = <COMMCOMMANDS>;



close(COMMCOMMANDS);

foreach $line(@commcommands){



print $line;





}







}





if($level >= $staff_rank){





open(STAFFCOMMANDS,"$root/txt/staffcommands.txt");



@staffcommands = <STAFFCOMMANDS>;



close(STAFFCOMMANDS);

foreach $line(@staffcommands){



print $line;





}







}





print "</PRE><p><a href=\"https://chat.ulyaoth.com/color/index.html\" target=_blank><b>CLICK HERE FOR COLOR LIST</b></a><p>\n";



require "$root/inc/check_pm.inc";



require "$root/inc/print_footer.inc";





exit;



}