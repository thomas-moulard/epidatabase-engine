<table cellpadding=0 cellspacing=0 width=100%>

	<tr>
		<td width=60% valign="top">
			
			<?
			$SQL = "SELECT * FROM epinews ORDER BY Date DESC Limit 0,1";
			$result = mysql_db_query("$nom_bdd" , $SQL , $connexion);
			while($resultat = mysql_fetch_array($result))
			{
				$Date = gmdate("d.m.Y", $resultat['Date']);
				$Titre = $resultat['Titre'];
				$Corps = str_replace("\n", "<br>", $resultat['Corps']);
			}
			?>
			
			<table cellpadding=10 cellspacing=0 width=100%>
				<tr>
					<td width=20>
						<img src="images/puce.gif">
					</td>
					<td valign="middle">
						<font class="h1">
							<?=$Titre?><br>
						</font>
						<font class="h0">
							<?=$Date?>
						</font>
					</td>
				</tr>
				
				<tr>
					<td colspan=2>
						<?=$Corps?>
					</td>
				</tr>
			
			</table>
			
		</td>
		<td width=8 bgcolor="#F1F1F1"></td>
		<td valign="top">
		
			<table cellpadding=10 cellspacing=0 width=100%>
				<tr>
					<td width=20>
						<img src="images/puce.gif">
					</td>
					<td valign="middle">
						<font class="h1">
							epi<font color="#000000">database</font><br>
						</font>
						<font class="h0">
							23.12.2004
						</font>
					</td>
				</tr>
				
				<tr>
					<td colspan=2>
						Il s'agit d'un projet de longue haleine qui sera d�velopp� tout au long de l'ann�e par un groupe de 
						trois �tudiants d'Epita.<br>
						<br>
						Cela consistera en la r�alisation compl�te d'une base de donn�es utilisable par des applications de base.<br>
						<br>
						Bas� sur la grammaire SQL, ce syst�me de gestion de base de donn�es sera pourvu des �l�ments suivants :<br>
						<br>
							&nbsp;&nbsp;&nbsp;<font color="#FF8800">Parseur</font><br>
							&nbsp;&nbsp;&nbsp;<font color="#FF8800">Interpr�teur</font><br>
							&nbsp;&nbsp;&nbsp;<font color="#FF8800">Application Client / Serveur</font><br>
					</td>
				</tr>
			
			</table>
		
		</td>
	</tr>
</table>