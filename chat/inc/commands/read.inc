#!/usr/bin/perl



print "Content-type: text/html\n\n";



require "$root/inc/print_header.inc";



open(OPBOARD,"$root/boards/opsboard.txt");



@postfile = <OPBOARD>;





@w = reverse(@postfile);



@s = @w[0..$lines];



@print_again = reverse(@s);



open(PRINTBOARD, ">$root/boards/opsboard.txt");



flock(PRINTBOARD,2);



print PRINTBOARD @print_again;



close(PRINTBOARD);





@postfile = reverse(@postfile);



close(OPBOARD);



$s = 0;



foreach $p(@postfile){



$s++;



($p1,$p2)=split(/\|\"\'\|/,$p);



$p2 =~ s/^\<!-- (([^ >]|\n)*) -->//ig;





if($level < $comm_rank){



print $p2;



}elsif($level >= $comm_rank){



print "<b><a href=\"$location?n=$DATA{'n'}&room=$room&id=$DATA{'id'}&msg=/bbclear+$p1\">DEL</a></b> | $p2";



       }



}



print "TOTAL: $s post(s).<br>\n";



require "$root/inc/check_pm.inc";





if($frames ne "yes"){



require "$root/inc/print_footer.inc";



exit;



}else{



print "</body>\n";



exit;





}

