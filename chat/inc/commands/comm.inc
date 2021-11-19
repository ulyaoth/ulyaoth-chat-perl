#!/usr/bin/perl



if ($command eq '/comm' && $level < 1){
                
        $errors = " Error, command $command not recognized, please use /help for a list of commands.";

return $errors;

exit;
}

@post = split(/\s+/,$DATA{'msg'});

$post = $DATA{'msg'};

$post =~ s/^\/comm//;


unless(@post[1]){

if($level < $comm_rank){

$errors = " Syntax: /comm [message].";

return $errors;

exit;

}else{

$errors = " $title committee links: || <a href=\"$location?n=$DATA{'n'}&id=$DATA{'id'}&room=$room&msg=/vcomm\"><b>Comm BB</b></a> || <a href=\"$location?n=$DATA{'n'}&id=$DATA{'id'}&room=$room&msg=/dir\"><b>Abuse Dir</b></a> || <a href=\"/cgi-bin\/fhome\/r.cgi\" target=_blank><b>Ban Logs</b></a> || <a href=\"$location?n=$DATA{'n'}&id=$DATA{'id'}&room=$room&msg=/deoplist\"><b>Deop List</b></a> || <a href=\"$location?n=$DATA{'n'}&id=$DATA{'id'}&room=$room&msg=/suspendlist\"><b>Suspend List</b></a> || <a href=\"$location?n=$DATA{'n'}&id=$DATA{'id'}&room=$room&msg=/commlist\"><b>Comm List</b></a> || <a href=\"$location?n=$DATA{'n'}&id=$DATA{'id'}&room=$room&msg=/record\"><b>Logs</b></a> ||.";
return $errors;

exit;

}

}


open(COMM,">>$root/boards/commbb.txt");

flock(COMM,2);

for (0..9) { $commid .= pack("C",65+int(rand(25.9999))); }

print COMM "$commid \|\"\'\|<!-- $commid --> <b>$DATA{'n'} ($realnick) from $room</b> ($ip) $fulltime<br> $post<p>\n";

close(COMM);

$errors = " <b>Flooding committee bulletin board will result in permanent account removal.</b><br>\n Time: $fulltime: $post";

return $errors;

exit;