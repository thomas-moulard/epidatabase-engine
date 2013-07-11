<table cellpadding=0 cellspacing=0 width=100%>

	<tr>
		<td width=100% valign="top">

			<?
			if((array_key_exists('Action', $_GET)) &&($_GET['Action'] == "admin"))
			{
				// Cherche le compte Admin
				$Total = 0;
				$SQL = "SELECT COUNT(idAdmin) As Nb FROM epiadmins 
						WHERE Pseudo='".$_POST['admin_pseudo']."' 
						AND Motdepasse='".$_POST['admin_pass']."'";
				$result = mysql_db_query("$nom_bdd" , $SQL , $connexion);
				while($resultat = mysql_fetch_array($result))
				{
					$Total = $resultat['Nb'];
				} 
				
				// Correct, on valide la session
				if($Total > 0)
					$_SESSION['logon'] = 1;
				
			}
			
			if((array_key_exists('logon', $_SESSION)) && ($_SESSION['logon'] == 1))
			{
			
				// Supprime une news
				if((array_key_exists('Action', $_GET)) && ($_GET['Action'] == "deletenews")&&($_GET['idNews'] != ""))
				{
					$SQL = "DELETE FROM epinews WHERE idNews = '".$_GET['idNews']."'";
					mysql_db_query("$nom_bdd" , $SQL , $connexion);
				}
				
				// Supprime un fichier
				if((array_key_exists('Action', $_GET)) && ($_GET['Action'] == "deletefile")&&($_GET['idFile'] != ""))
				{
					$SQL = "DELETE FROM epifiles WHERE idFile= '".$_GET['idFile']."'";
					mysql_db_query("$nom_bdd" , $SQL , $connexion);
				}
				
				// Ajoute une news
				if((array_key_exists('Action', $_GET)) && ($_GET['Action'] == "newnews"))
				{
					$SQL = "INSERT INTO epinews(Titre, Corps, Date) 
					VALUES('".addslashes($_POST['news_titre'])."', '".addslashes($_POST['news_corps'])."', '".time()."')";
					mysql_db_query("$nom_bdd" , $SQL , $connexion);
				}
				
				// Ajoute un fichier
				if((array_key_exists('Action', $_GET)) && ($_GET['Action'] == "newfile"))
				{
					$SQL = "INSERT INTO epifiles(Nom, Description, Fichier) 
					VALUES('".addslashes($_POST['file_nom'])."', '".addslashes($_POST['file_description'])."', '".addslashes($_POST['file_url'])."')";
					mysql_db_query("$nom_bdd" , $SQL , $connexion);
				}
				
			?>
			<script language="javascript">
				function sendConfirm(url, objet)
				{
					var input = confirm("Voulez-vous supprimer " + objet + " ?");
					if(input)
						document.location.href = url;
				}
			</script>
			
			<font class="h1">Gestion des News</font> [<a href="<?=$racine?>/index.php?Tab=<?=$_GET['Tab']?>#NouvelleNews">Nouvelle News</a>]<br>
			<center>
				<table cellpadding=3 cellspacing=1 width=80%>
					<tr>
						<td class="entete" align="center">Titre</td>
						<td class="entete" align="center">Corps</td>
						<td class="entete" align="center">Date</td>
						<td class="entete" align="center">Actions</td>
					</tr>
				<?
				$SQL = "SELECT * FROM epinews ORDER BY Date DESC";
				$result = mysql_db_query("$nom_bdd" , $SQL , $connexion);
				$i = 0;
				while($resultat = mysql_fetch_array($result))
				{
				?>
					<tr>
						<td class="cellule<?=(fmod($i,2)+1)?>"><?=$resultat['Titre']?></td>
						<td class="cellule<?=(fmod($i,2)+1)?>"><?=substr(str_replace("\n", "<br>", $resultat['Corps']), 0, 120)?>...</td>
						<td class="cellule<?=(fmod($i,2)+1)?>" align="center"><?=gmdate("d.m.Y", $resultat['Date'])?></td>
						<td class="cellule<?=(fmod($i,2)+1)?>" align="center"><a href="javascript:sendConfirm('<?=$racine?>/index.php?Tab=<?=$_GET['Tab']?>&Action=deletenews&idNews=<?=$resultat['idNews']?>', 'cette news');">Supprimer</a></td>
					</tr>
				<?
					$i++;
				}
				if($i == 0)
				{
				?>
					<tr>
						<td class="cellule1" align="center" colspan=4>
							Pas de news répertoriées.<br>
						</td>
					</tr>
				<?
				}
				?>
				</table>
			</center>
			
			<br>
			
			<font class="h1">Gestion des Fichiers</font> [<a href="<?=$racine?>/index.php?Tab=<?=$_GET['Tab']?>#NouveauFichier">Nouveau Fichier</a>]<br>
			<center>
				<table cellpadding=3 cellspacing=1 width=80%>
					<tr>
						<td class="entete" align="center">Nom</td>
						<td class="entete" align="center">Description</td>
						<td class="entete" align="center">Fichier</td>
						<td class="entete" align="center">Actions</td>
					</tr>
				<?
				$SQL = "SELECT * FROM epifiles";
				$result = mysql_db_query("$nom_bdd" , $SQL , $connexion);
				$i = 0;
				while($resultat = mysql_fetch_array($result))
				{
				?>
					<tr>
						<td class="cellule<?=(fmod($i,2)+1)?>"><?=$resultat['Nom']?></td>
						<td class="cellule<?=(fmod($i,2)+1)?>"><?=substr(str_replace("\n", "<br>", $resultat['Description']), 0, 120)?>...</td>
						<td class="cellule<?=(fmod($i,2)+1)?>" align="center"><?=$resultat['Fichier']?></td>
						<td class="cellule<?=(fmod($i,2)+1)?>" align="center"><a href="javascript:sendConfirm('<?=$racine?>/index.php?Tab=<?=$_GET['Tab']?>&Action=deletefile&idFile=<?=$resultat['idFile']?>', 'ce fichier');">Supprimer</a></td>
					</tr>
				<?
					$i++;
				}
				if($i == 0)
				{
				?>
					<tr>
						<td class="cellule1" align="center" colspan=4>
							Pas de fichiers répertoriés.<br>
						</td>
					</tr>
				<?
				}
				?>
				</table>
			</center>
			
			<br>
			
			<script language="javascript">
				function verifNews()
				{
					if((document.news.news_titre.value != "")&&(document.news.news_corps.value != ""))
						document.news.submit();
					else
						alert('Remplissez le formulaire correctement !');
				}
			</script>
			
			<a name="NouvelleNews"></a>
			<font class="h1">Nouvelle News</font><br>
			<center>
				<form name="news" method="post" action="<?=$racine?>/index.php?Tab=<?=$_GET['Tab']?>&Action=newnews">
				<table cellpadding=3 cellspacing=0 width=60%>
					<tr>
						<td align="left" valign="top" width=40%>
							<b>Titre</b>
						</td>
						<td align="left" valign="top">
								<input type="text" name="news_titre" class="input_text">
						</td>
					</tr>
					<tr>
						<td align="left" valign="top" width=40%>
							<b>Corps</b>
						</td>
						<td align="left" valign="top">
								<textarea name="news_corps" cols=50 rows=5 class="input_text"></textarea>
						</td>
					</tr>
					<tr>
						<td colspan=2 align="center" valign="middle">
							<input type="button" class="input_button" value="Valider" onclick="javascript:verifNews();">
						</td>
					</tr>
				</table>
				</form>
			</center>
			
			<br>
			
			<script language="javascript">
				function verifFile()
				{
					if((document.file.file_nom.value != "")&&(document.file.file_description.value != "")&&(document.file.file_url.value != ""))
						document.file.submit();
					else
						alert('Remplissez le formulaire correctement !');
				}
			</script>
			
			<a name="NouveauFichier"></a>
			<font class="h1">Nouveau Fichier</font><br>
			<center>
				<form name="file" method="post" action="<?=$racine?>/index.php?Tab=<?=$_GET['Tab']?>&Action=newfile">
				<table cellpadding=3 cellspacing=0 width=60%>
					<tr>
						<td align="left" valign="top" width=40%>
							<b>Nom</b>
						</td>
						<td align="left" valign="top">
								<input type="text" name="file_nom" class="input_text">
						</td>
					</tr>
					<tr>
						<td align="left" valign="top" width=40%>
							<b>Fichier </b>(fichier.ext)
						</td>
						<td align="left" valign="top">
								<input type="text" name="file_url" class="input_text">
						</td>
					</tr>
					<tr>
						<td align="left" valign="top" width=40%>
							<b>Description</b>
						</td>
						<td align="left" valign="top">
								<textarea name="file_description" cols=50 rows=5 class="input_text"></textarea>
						</td>
					</tr>
					<tr>
						<td colspan=2 align="center" valign="middle">
							<input type="button" class="input_button" value="Valider" onclick="javascript:verifFile();">
						</td>
					</tr>
				</table>
				</form>
			</center>
			<?
			}
			else
			{
			?>
			
			<script language="javascript">
				function verifAdmin()
				{
					if((document.admin.admin_pseudo.value != "")&&(document.admin.admin_pass.value != ""))
						document.admin.submit();
					else
						alert('Remplissez le formulaire correctement !');
				}
			</script>
			<center>
			<form name="admin" method="post" action="<?=$racine?>/index.php?Tab=<?=$_GET['Tab']?>&Action=admin">
			<table cellpadding=3 cellspacing=0 width=60%>
				<tr>
					<td align="left" valign="top" width=40%>
						<b>Pseudo</b>
					</td>
					<td align="left" valign="top">
							<input type="text" name="admin_pseudo" class="input_text">
					</td>
				</tr>
				<tr>
					<td align="left" valign="top" width=40%>
						<b>Mot de passe</b>
					</td>
					<td align="left" valign="top">
							<input type="password" name="admin_pass" class="input_text">
					</td>
				</tr>
				<tr>
					<td colspan=2 align="center" valign="middle">
						<input type="button" class="input_button" value="Envoyer" onclick="javascript:verifAdmin();">
					</td>
				</tr>
			</table>
			</form>
			</center>
			<?
			}
			?>
			
		</td>
	</tr>
</table>