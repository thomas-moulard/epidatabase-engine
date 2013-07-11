# phpMyAdmin MySQL-Dump
# version 2.3.0
# http://phpwizard.net/phpMyAdmin/
# http://www.phpmyadmin.net/ (download page)
#
# Serveur: localhost
# G�n�r� le : Lundi 28 F�vrier 2005 � 03:22
# Version du serveur: 4.00.17
# Version de PHP: 4.2.3
# Base de donn�es: `epidatabase`
# --------------------------------------------------------

#
# Structure de la table `epiadmins`
#

CREATE TABLE epiadmins (
  idAdmin int(6) NOT NULL auto_increment,
  Pseudo varchar(255) NOT NULL default '',
  Motdepasse varchar(255) NOT NULL default '',
  PRIMARY KEY  (idAdmin),
  UNIQUE KEY idAdmin (idAdmin)
) TYPE=MyISAM;

#
# Contenu de la table `epiadmins`
#

INSERT INTO epiadmins VALUES (1, 'epidatabaseadmin', 'extamp2008');
# --------------------------------------------------------

#
# Structure de la table `epifiles`
#

CREATE TABLE epifiles (
  idFile int(6) NOT NULL auto_increment,
  Nom varchar(255) NOT NULL default '',
  Description text NOT NULL,
  Fichier varchar(255) NOT NULL default '',
  PRIMARY KEY  (idFile),
  UNIQUE KEY idFile (idFile)
) TYPE=MyISAM;

#
# Contenu de la table `epifiles`
#

INSERT INTO epifiles VALUES (2, 'Rapport 1', 'Rapport de la Soutenance 1 du Projet.', 'rapport_1.pdf');
INSERT INTO epifiles VALUES (3, 'Rapport 2', 'Rapport de la Soutenance 2 du Projet.', 'rapport_2.pdf');
# --------------------------------------------------------

#
# Structure de la table `epinews`
#

CREATE TABLE epinews (
  idNews int(6) NOT NULL auto_increment,
  Titre varchar(255) NOT NULL default '',
  Corps text NOT NULL,
  Date int(16) NOT NULL default '0',
  PRIMARY KEY  (idNews),
  UNIQUE KEY idNews (idNews)
) TYPE=MyISAM;

#
# Contenu de la table `epinews`
#

INSERT INTO epinews VALUES (2, 'Mise en ligne du Site', 'Le site relatif au projet d\'Epita <font color="#FF8800">epi</font>database ouvre ses portes.\r\n\r\nActuellement, l\'interface se divise en cinq diff�rentes sections qui �volueront en m�me temps que le projet lui-m�me.\r\n\r\nD�tails des diff�rentes sections :\r\n						&nbsp;&nbsp;&nbsp;<font color="#FF8800">Accueil</font> : page principale sur laquelle figurent toutes les nouveaut�s majeures concernant l\'�tat d\'avancement du projet.\r\n						&nbsp;&nbsp;&nbsp;<font color="#FF8800">Projet</font> : documentation relative au projet et d�taillant avec pr�cision les objectifs et les points essentiels de ce dernier.\r\n						&nbsp;&nbsp;&nbsp;<font color="#FF8800">Avancement</font> : d�tail complet graphique de l\'�tat d\'avancement des diff�rentes t�ches du projet.\r\n\r\n						&nbsp;&nbsp;&nbsp;<font color="#FF8800">T�l�chargements</font> : liste de tous les fichiers en rapport avec le projet : cahier des charges, rapports...\r\n						&nbsp;&nbsp;&nbsp;<font color="#FF8800">Contact</font> : formulaire pour entrer en contact avec l\'�quipe de d�veloppement.', 0);
INSERT INTO epinews VALUES (3, 'Soutenance 2', 'La Soutenance 2 cl�ture la deuxi�me �tape de d�veloppement d\'<font color="#FF8800">epiDatabase</font> avec la mise en place des �l�ments principaux :\r\n\r\n - <font color="#FF8800">Parseur</font> : analyser les requ�tes SQL\r\n\r\n - <font color="#FF8800">Lexeur</font> : rediriger les requ�tes SQL vers le syst�me de fichiers\r\n\r\n - <font color="#FF8800">Gestion des Requ�tes</font> : traitement des donn�es � partir des requ�tes SQL\r\n\r\n - <font color="#FF8800">Site Web</font> compl�tement op�rationnel', 1109557053);

