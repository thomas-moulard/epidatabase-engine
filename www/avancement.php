<script language="javascript">
	function progressbar(valeur)
	{
		var couleur;
		if(valeur < 26)
			couleur = "#C4ED9A";
		else
		{
			if(valeur < 51)
				couleur = "#9FDC61";
			else
			{
				if(valeur < 76) 
					couleur = "#7ACA28";
				else
					couleur = "#60BE01";	
			}
		}
		document.write('<table cellpadding=0 cellspacing=0 width=' + valeur +'% height=100%>');
		document.write('<tr><td width=100% height=100% style=padding:2 bgcolor=' + couleur + ' align=center><b>' + valeur + '%</b></td></tr>');
		document.write('</table>');
	}
</script>

<table cellpadding=0 cellspacing=0 width=100%>

	<tr>
		<td width=100% valign="top">

			<font class="h1">Soutenance 1</font><br>
			<table cellpadding=2 cellspacing=0 width=100%>
				<tr>
					<td height=1 colspan=2 bgcolor="#F1F1F1"></td>
				</tr>
				<tr>
					<td width=50%>
					  Recherches Fonctionnement SGBD
					</td>
					<td width=50%>
						<script language="javascript">
							progressbar(100);
						</script>
					</td>
				</tr>
				<tr>
					<td height=1 colspan=2 bgcolor="#F1F1F1"></td>
				</tr>
				<tr>
					<td width=50%>
					  Recherches Parseur
					</td>
					<td width=50%>
						<script language="javascript">
							progressbar(100);
						</script>
					</td>
				</tr>
				<tr>
					<td height=1 colspan=2 bgcolor="#F1F1F1"></td>
				</tr>
				<tr>
					<td width=50%>
					  Premiers aperçus du parseur
					</td>
					<td width=50%>
						<script language="javascript">
							progressbar(100);
						</script>
					</td>
				</tr>
				<tr>
					<td height=1 colspan=2 bgcolor="#F1F1F1"></td>
				</tr>
				<tr>
					<td width=50%>
					  Mise en place du système de fichiers
					</td>
					<td width=50%>
						<script language="javascript">
							progressbar(100);
						</script>
					</td>
				</tr>
				<tr>
					<td height=1 colspan=2 bgcolor="#F1F1F1"></td>
				</tr>
				<tr>
					<td width=50%>
					  Graphisme Site Web
					</td>
					<td width=50%>
						<script language="javascript">
							progressbar(100);
						</script>
					</td>
				</tr>
				<tr>
					<td height=1 colspan=2 bgcolor="#F1F1F1"></td>
				</tr>
				<tr>
					<td width=50%>
					  LateX
					</td>
					<td width=50%>
						<script language="javascript">
							progressbar(100);
						</script>
					</td>
				</tr>
				<tr>
					<td height=15 colspan=2 bgcolor="#F1F1F1"></td>
				</tr>
			</table>
			
			<font class="h1">Soutenance 2</font><br>
			<table cellpadding=2 cellspacing=0 width=100%>
				<tr>
					<td height=1 colspan=2 bgcolor="#F1F1F1"></td>
				</tr>
				<tr>
					<td width=50%>
					  Recherches diverses
					</td>
					<td width=50%>
						<script language="javascript">
							progressbar(100);
						</script>
					</td>
				</tr>
				<tr>
					<td height=1 colspan=2 bgcolor="#F1F1F1"></td>
				</tr>
				<tr>
					<td width=50%>
					  Gestion des requêtes 1
					</td>
					<td width=50%>
						<script language="javascript">
							progressbar(100);
						</script>
					</td>
				</tr>
				<tr>
					<td height=1 colspan=2 bgcolor="#F1F1F1"></td>
				</tr>
				<tr>
					<td width=50%>
					  Suite de la création du parseur
					</td>
					<td width=50%>
						<script language="javascript">
							progressbar(100);
						</script>
					</td>
				</tr>
				<tr>
					<td height=1 colspan=2 bgcolor="#F1F1F1"></td>
				</tr>
				<tr>
					<td width=50%>
					  Implémentation 1 de l'interprêteur
					</td>
					<td width=50%>
						<script language="javascript">
							progressbar(100);
						</script>
					</td>
				</tr>
				<tr>
					<td height=1 colspan=2 bgcolor="#F1F1F1"></td>
				</tr>
				<tr>
					<td width=50%>
					  Site Web
					</td>
					<td width=50%>
						<script language="javascript">
							progressbar(100);
						</script>
					</td>
				</tr>
				<tr>
					<td height=1 colspan=2 bgcolor="#F1F1F1"></td>
				</tr>
				<tr>
					<td width=50%>
					  LateX
					</td>
					<td width=50%>
						<script language="javascript">
							progressbar(100);
						</script>
					</td>
				</tr>
				<tr>
					<td height=15 colspan=2 bgcolor="#F1F1F1"></td>
				</tr>
			</table>
			
			<font class="h1">Soutenance 3</font><br>
			<table cellpadding=2 cellspacing=0 width=100%>
				<tr>
					<td height=1 colspan=2 bgcolor="#F1F1F1"></td>
				</tr>
				<tr>
					<td width=50%>
					  Fin implémentation du parseur
					</td>
					<td width=50%>
						<script language="javascript">
							progressbar(75);
						</script>
					</td>
				</tr>
				<tr>
					<td height=1 colspan=2 bgcolor="#F1F1F1"></td>
				</tr>
				<tr>
					<td width=50%>
					  Implémentation 2 de l'interprêteur
					</td>
					<td width=50%>
						<script language="javascript">
							progressbar(75);
						</script>
					</td>
				</tr>
				<tr>
					<td height=1 colspan=2 bgcolor="#F1F1F1"></td>
				</tr>
				<tr>
					<td width=50%>
					  Gestion des requêtes 2
					</td>
					<td width=50%>
						<script language="javascript">
							progressbar(0);
						</script>
					</td>
				</tr>
				<tr>
					<td height=1 colspan=2 bgcolor="#F1F1F1"></td>
				</tr>
				<tr>
					<td width=50%>
					  Interconnexion Réseau
					</td>
					<td width=50%>
						<script language="javascript">
							progressbar(10);
						</script>
					</td>
				</tr>
				<tr>
					<td height=1 colspan=2 bgcolor="#F1F1F1"></td>
				</tr>
				<tr>
					<td width=50%>
					  Site Web
					</td>
					<td width=50%>
						<script language="javascript">
							progressbar(100);
						</script>
					</td>
				</tr>
				<tr>
					<td height=1 colspan=2 bgcolor="#F1F1F1"></td>
				</tr>
				<tr>
					<td width=50%>
					  LateX
					</td>
					<td width=50%>
						<script language="javascript">
							progressbar(0);
						</script>
					</td>
				</tr>
				<tr>
					<td height=15 colspan=2 bgcolor="#F1F1F1"></td>
				</tr>
			</table>
			
			<font class="h1">Soutenance 4</font><br>
			<table cellpadding=2 cellspacing=0 width=100%>
				<tr>
					<td height=1 colspan=2 bgcolor="#F1F1F1"></td>
				</tr>
				<tr>
					<td width=50%>
					  Fin implémentation de l'interprêteur
					</td>
					<td width=50%>
						<script language="javascript">
							progressbar(0);
						</script>
					</td>
				</tr>
				<tr>
					<td height=1 colspan=2 bgcolor="#F1F1F1"></td>
				</tr>
				<tr>
					<td width=50%>
					  Fin de l'implémentation Réseau
					</td>
					<td width=50%>
						<script language="javascript">
							progressbar(0);
						</script>
					</td>
				</tr>
				<tr>
					<td height=1 colspan=2 bgcolor="#F1F1F1"></td>
				</tr>
				<tr>
					<td width=50%>
					  Application concrête
					</td>
					<td width=50%>
						<script language="javascript">
							progressbar(0);
						</script>
					</td>
				</tr>
				<tr>
					<td height=1 colspan=2 bgcolor="#F1F1F1"></td>
				</tr>
				<tr>
					<td width=50%>
					  Corrections de bugs
					</td>
					<td width=50%>
						<script language="javascript">
							progressbar(0);
						</script>
					</td>
				</tr>
				<tr>
					<td height=1 colspan=2 bgcolor="#F1F1F1"></td>
				</tr>
				<tr>
					<td width=50%>
					  Site Web
					</td>
					<td width=50%>
						<script language="javascript">
							progressbar(100);
						</script>
					</td>
				</tr>
				<tr>
					<td height=1 colspan=2 bgcolor="#F1F1F1"></td>
				</tr>
				<tr>
					<td width=50%>
					  LateX
					</td>
					<td width=50%>
						<script language="javascript">
							progressbar(0);
						</script>
					</td>
				</tr>
			</table>
			
		</td>
	</tr>
</table>