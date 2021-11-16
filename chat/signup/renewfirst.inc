print "Content-type: text/html\n\n";

print "<HEAD><title>$title Chat Ops Application / RENEWAL!</TITLE>\n";

print "<BODY BGCOLOR=\"000000\" TEXT=\"FFFFFF\" onLoad=\"window.status='$title Chat Operator Application'\">\n";

print "<b><center>$title Chat / MEMBERSHIP RENEWAL.</center></b><p>\n";

print "<FORM METHOD=\"POST\" ACTION=\"$loc\">\n";

print "<center><table width=500><tr><td><b><font size=-1>\n";

print "<u>OPS ACCOUNT RENEWAL.</u><p>\n";


print<<text;
        
<center>

<textarea rows=10 cols=80 wrap=virtual name=contract>

$title is a friendly chat, so please respect these rules!  Thank you!

DISCLAIMER:  As a user of $title Chat service, you agree to waive all rights to direct or indirect legal action against $title Chat.  $title is not responsible in any way for user generated content on our site.  $title is not directly or indirectly for the effects of site content or denial of access to services.

1. LANGUAGE:  Swearing in public rooms is not permitted here.  If you use words like "fuck" (or f*ck, phuq, fluck, etc.) you can be warned, kicked, or banned.  Other words such as "shit" and "ass" need to be taken in context.   You may swear in private rooms, as long as they are locked and everybody in the room agrees to it.  

2. RACISM:  Racism is NOT tolerated here in any shape or form.  This is an international site and all users are welcome, regardless of age, sex, religion, or origin.  Posting racist/sexist messages constitutes a kick and/or ban.

3. INSULTS/HARASSMENT:  Insulting and/or harassing people is NOT permitted here, and you will be warned, kicked and/or banned for doing so.  This is a friendly chat, so please try to make the experience enjoyable!

4. LEWDNESS:  Posting lewd messages on the main (words, images, etc.) is grounds for kicking.  Many underage people chat here so the conversation must be kept clean. 

5. FLOODING:  Rapidly or repeatedly posting a message is termed FLOODING and is not acceptable here, as it is annoying and it wastes bandwidth.  Flooding constitutes a warning, kick, or ban, depending on the situation.

6. ADVERTISING:  Advertising for other chat sites and/or pornographic sites is not permitted.  You will be warned and then banned if it continues.

7. NICKNAMES:  Nicknames must be decent and conform to the chat rules.  If an Operator asks you to change your nickname, please do so immediately.

8. REPOSTING:  Reposting private messages on the main is not allowed; it's rude and it wastes bandwidth.  Please respect people's privacy!

9. KICKING/BANNING:  The /kick and /ban commands are to be used as a last resort only and MUST have a valid reason.  Kick and ban wars between Operators will not be tolerated, and is grounds for suspension and/or being deoped.  Kicking and banning in locked private rooms is also not permitted.  Any Operators caught abusing these commands will be suspended and/or deoped.

10. CLEARING:  Operators rank 6 and up have the ability to /clear the room.  You need a valid reason to /clear; if this is abused you will be kicked.  Valid reasons for clearing are swearing, lewdness, flooding, advertising, racism, personal information being posted on the main, and accidental reposting.

11. ABUSE OF OPS:  Any Operator caught abusing their privileges will be kicked and/or banned.  If this happens three times, the offending Operator will be suspended and/or deoped.

***FOR YOUR OWN SAFETY:  Please do NOT post personal information (IE. Your address, phone number, etc.) on the main!


</textarea>
</center>



text


print "<input type=hidden name=\"bypass\" value=\"04285042\">\n\n";

print "<p>\n<center><INPUT TYPE=SUBMIT Value=\" I AGREE / ACCEPT \"></center>\n";

print "</table>\n\n";

print "</body></html>";



return true;

