#!/usr/bin/perl


if($command eq '/report' && $level < $comm_rank){


$errors = " Error, command $command not recognized, please use /help for a list of commands.";
        
return $errors;

exit;


}


@report = split(/\s+/,$DATA{'msg'});


print "Content-type: text/html\n\n";

require "$root/inc/print_header.inc";

open(REP,"$root/abuse/reports/@report[1].txt");

flock(REP,1);

@r = <REP>;

$s = 0;

close(REP);

foreach $c(@r){

print $c;

}



print "<p>\n";

$errors = "<center>|| <a href=\"$location?n=$DATA{'n'}&id=$DATA{'id'}&room=$room&msg=/vcomm\"><b>Comm BB</b></a> || <a href=\"$location?n=$DATA{'n'}&id=$DATA{'id'}&room=$room&msg=/dir\"><b>Abuse Dir</b></a> || <a href=\"$banlogs\" target=_blank><b>Ban Logs</b></a> || <a href=\"$location?n=$DATA{'n'}&id=$DATA{'id'}&room=$room&msg=/deoplist\"><b>Deop List</b></a> || <a href=\"$location?n=$DATA{'n'}&id=$DATA{'id'}&room=$room&msg=/commlist\"><b>Comm List</b></a>||</center><br>\n";


require "$root/inc/check_pm.inc";


require "$root/inc/print_footer.inc";

exit;