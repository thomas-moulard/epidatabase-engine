<table cellpadding=0 cellspacing=0 width=100%>

	<tr>
		<td width=100% align="center" valign="top">
		
		<?
		if(( array_key_exists ("Action", $_GET)) && ($_GET['Action'] == "contact"))
		{
			// Envoi de l'e-mail
			$objet = addslashes($_POST['contact_objet']);
			$message = addslashes(str_replace("\n", "<br>", $_POST['contact_message']));
			$email = addslashes($_POST['contact_email']);
			mail($contact_email, $objet, $message);
		?>
			<br>
			<b>Votre message a bien été envoyé et sera pris en considération dès que possible.</b><br>
			<br>
		<?
		}
		else
		{
		?>
			<script language="javascript">
				function verifContact()
				{
					if((document.contact.contact_email.value != "")&&(document.contact.contact_objet.value != "")&&(document.contact.contact_message.value != ""))
						document.contact.submit();
					else
						alert('Remplissez le formulaire correctement !');
				}
			</script>

			<form name="contact" method="post" action="<?=$racine?>/index.php?Tab=<?=$_GET['Tab']?>&Action=contact">
			<table cellpadding=3 cellspacing=0 width=60%>
				<tr>
					<td align="left" valign="top" width=40%>
						<b>Objet</b>
					</td>
					<td align="left" valign="top">
							<input type="text" name="contact_objet" class="input_text">
					</td>
				</tr>
				<tr>
					<td align="left" valign="top" width=40%>
						<b>E-mail</b>
					</td>
					<td align="left" valign="top">
							<input type="text" name="contact_email" class="input_text">
					</td>
				</tr>
				<tr>
					<td align="left" valign="top" width=40%>
						<b>Message</b>
					</td>
					<td align="left" valign="top">
							<textarea name="contact_message" cols=50 rows=10 class="input_text"></textarea>
					</td>
				</tr>
				<tr>
					<td colspan=2 align="center" valign="middle">
						<input type="button" class="input_button" value="Envoyer" onclick="javascript:verifContact();">
					</td>
				</tr>
			</table>
			</form>
		<?
		}
		?>
			
		</td>
	</tr>
</table>