<table cellpadding=0 cellspacing=0 width=100%>

	<tr>
		<td width=100% align="center" valign="top">
			
			<br>
			
			<table cellpadding=10 cellspacing=0 width=60%>
				
				<?
				$SQL = "SELECT * FROM epifiles ORDER BY Nom";
				$result = mysql_db_query("$nom_bdd" , $SQL , $connexion);
				while($resultat = mysql_fetch_array($result))
				{
				?>
				<tr>
					<td class="cellule2"><img src="<?=$racine?>/images/<?=substr($resultat['Fichier'], strlen($resultat['Fichier'])-3)?>.gif"></td>
					<td class="cellule2">
						<a href="<?=$racine?>/files/<?=$resultat['Fichier']?>"><b><?=$resultat['Nom']?></b></a><br>
						<?=str_replace("\n", "<br>", $resultat['Description'])?>
					</td>
				</tr>
				<?
				}
				?>
			
			</table>
			
			<br>
			
		</td>
	</tr>
</table>