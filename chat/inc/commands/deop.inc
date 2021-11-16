#!/usr/bin/perl


if($command eq '/deop' && $level < $comm_rank){
                
        $errors = " Error, command $command not recognized, please use /help for a list of commands.";
return $errors;

exit;
        
}
        
@deop = split(/\s+/, $DATA{'msg'});

$reason = $DATA{'msg'};

$reason =~ s/^\/deop//;

$reason =~ s/\s+//;


$reason =~ s/^@deop[1]//;

@deop[1] =~ s/[^\w]//g;

@deop[1]=substr(@deop[1],0,14);


unless(@deop[2]){


$errors = " Syntax: /deop [nick] [reason].";

return $errors;

exit;



}

if(!-e "$root/ops/ops/@deop[1]"){


$errors = " Error, user <b>@deop[1]</b> is not an Operator.";

return $errors;

exit;

}

if(@deop[1] eq $opsnick){


$errors = " Error, not allowed.";

return $errors;

exit;


}

if(-e "$root/deop/@deop[1]"){


$errors = " Error, Operator <b>@deop[1]</b> is already deopped.";

return $errors;

exit;

}


dbmopen(%DEOP,"$root/ops/ops/@deop[1]",0777);

$dlevel = $DEOP{'level'};

dbmclose(%DEOP);

if($dlevel >= $comm_rank){

$errors = " Error, this action is not allowed.";

return $errors;

exit;

}


dbmopen(%D,"$root/deopped/@deop[1]",0777);


$D{'owner'} = $realnick;


$D{'deop'} = "*** Operator <b>@deop[1]</b> deopped by <b>$realnick</b> for ($reason). Time: $fulltime.";


dbmclose(%D);

dbmopen(%R,"$root/ops/ops/@deop[1]",0777);

$R{'record_deops'}++;

dbmclose(%R);



$errors = " Operator <b>@deop[1]</b> deopped. Please clear your deop reason by posting a message on comm board. However this action is logged and will be fully controled by Staff members.";



return $errors;

exit;













