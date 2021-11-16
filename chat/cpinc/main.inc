#!/usr/bin/perl

print <<"(END HTML FOOTER)";

<HTML>
<HEAD>
</HEAD>
<BODY>
<CENTER><FONT COLOR="#FF0000" SIZE="+5">Operators Control Panel - $title</FONT></CENTER>
<BLOCKQUOTE>
<BLOCKQUOTE>
<BLOCKQUOTE>
<P>Ops account <B>$DATA{'ops'}</B> Current ip address: <b>$ENV{'REMOTE_ADDR'}</b>. Welcome to Control Panel.</P>
This program is an additional tool for you to manage your account information, check 
your chatmail, change your current password to another, check online users, and much more. 
Please note that we have put all the security required to maintain your account usibility 
by you and only you, and now it's your responsibility to help us doing so but not sharing 
any links or passwords with others to avoid being hacked by hackers.
<BR><BR><B>$title</B> Admin.</BLOCKQUOTE>
</BLOCKQUOTE>
</BLOCKQUOTE>
</BODY>
</HTML>

(END HTML FOOTER)

return true;
