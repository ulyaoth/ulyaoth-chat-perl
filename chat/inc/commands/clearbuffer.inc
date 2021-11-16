#!/usr/bin/perl

if($command eq '/clearbuffer' && $level >= $comm_rank){

print "Content-type: text/html\n\n";

require "$root/inc/print_header.inc";

open(CBUFFER,"$root/clearlog/$time_file.txt");

flock(CBUFFER,1);

@cl = <CBUFFER>;

print @cl;

close(CBUFFER);

require "$root/inc/check_pm.inc";

if($frames ne 'yes'){

require "$root/inc/print_footer.inc";

}else{

print "</body>";

}

exit;

}

if($command eq '/clearbuffer' && $comm_rank < 1){
                
$errors = " Command $command not recognized, please use /help for a list of commands.";

return $errors;

exit;

}
