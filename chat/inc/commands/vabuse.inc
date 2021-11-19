#!/usr/bin/perl


if($command eq '/vabuse' && $level < $comm_rank){


$errors = " Error, command $command not recognized, please use /help for a list of commands.";
        
return $errors;

exit;


}


@vabuse = split(/\s+/,$DATA{'msg'});


print "Content-type: text/html\n\n";

require "$root/inc/print_header.inc";

open(REP,"$root/abuse/@vabuse[1].txt");

flock(REP,1);

@r = <REP>;

$s = 0;

close(REP);

foreach $c(@r){
$s++;

($p1,$p2)=split(/\|\"\'\|/,$c);

$p2 =~ s/^\<!-- (([^ >]|\n)*) -->//ig;

print "$p2 || <b><a href=\"$location?n=$DATA{'n'}&room=$room&id=$DATA{'id'}&msg=/report+$p1\">CHECK</a></b>||<br>\n";

}


print "<p>\nTOTAL: $s report(s).<br>\n";

require "$root/inc/check_pm.inc";


require "$root/inc/print_footer.inc";

exit;