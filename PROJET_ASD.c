
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//PARTIE 1

int nbetud (char matcin[100][8]){
    int i,j,pos=0;
    char ch1[8];
       for (i=0;i<100;i++){
            for (j=0;j<8;j++){
                    ch1[j]=matcin[i][j];
                }

                int c=0;
                for(int k=0;k<8;k++)
                    if(ch1[k]=='0')
                        c++;
                if (c==8){
                    pos=i;

                }
              if(pos!=0)
                    break;
            }
        return pos;
        }


void afficher (int i, char matcin[100][8],char matnom[100][20],char matpnom[100][20], char matspec[100][9],int tab_grp[100], int tab_nbabs[100] ){
    char ch[8],ch1[20],ch2[20],ch3[9];
						printf("\n");
						int k=0;
                        for (k=0;k<8;k++){
                            ch[k]=matcin[i][k];
                        }

                        printf("CIN: %s\n", ch);
                        fflush(stdin);

                        for (k=0;k<20;k++){
                            ch1[k]=matnom[i][k];
                        }
                        printf("Nom: %s\n", ch1);

                        for (k=0;k<20;k++){
                            ch2[k]=matpnom[i][k];
                        }
                        printf("Prenom: %s\n", ch2);

                        for (k=0;k<9;k++){
                            ch3[k]=matspec[i][k];
                        }
                        printf("Specialite: %s\n", ch3);



					}
//procedure recherche selon choix


void recherche( char matcin[100][8],char matnom[100][20],char matpnom[100][20],char matspec[100][9],int tab_grp[100], int tab_abs[100] )
	{
	    int re,i,j,pos,c;
        char x[20],x2[20],ch[8],ch1[20],chn[20],chsp[20];

        pos=nbetud(matcin);

		do
        {
            printf("Veuillez Choisir Rechercher Selon\n1.CIN\n2.NOM\n3.SPECIALITE\n");
            scanf("%d",&re);
        }while(re!=1 && re!=2 && re!=3);

        if(re==1){
            printf("Saisir le numero CIN: ");
            fflush(stdin);
            scanf("%[^\n]s", x);

            for(i=0;i<pos;i++){
                for (j=0;j<8;j++)
                   {ch[j]=matcin[i][j];}
                c=0;
                while(c<8 && ch[c]==x[c])
                    {c++;}
                    if(c==8){
                    afficher(i,matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
                    }
            }


		}

        else if (re==2){
        printf("Saisir le nom: ");
        fflush(stdin);
		gets(x);


        for(i=0;i<pos;i++){
            for(j=0;j<strlen(x);j++){
                    chn[j]=matnom[i][j];
                    }
                    fflush(stdin);


			if(strcmp(chn,x)==0)
					{
                        afficher(i,matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
		}

        }
        }
        else{
        printf("Saisir la specialite: ");
        fflush(stdin);
		gets(x);
		if(strlen(x)==7)
            x[8]=' ';
        for(int i = 0; i < pos; i++){
            for (int j=0;j<8;j++){
                chsp[j]=matspec[i][j];
            }

				if(strcmp(chsp,x)==0)
                    afficher(i,matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
            }


        }
	}

//remplir matrice avec des cin
void remplirmatcin (char matcin[100][8]){
    int i=0,j=0,p;
    int pos;
    char ch[8],ch1[8];
            printf("Entrez la carte d'identit\x8A de l'etudiant.\n ");
            do{
            printf("Veuillez saisir un num\x8Aro de carte d'identit\x8A valide:");
            fflush(stdin);
            gets(ch);
            //fflush(stdin);
            p=0;
            while(p<8 && ch[p]>='0' && ch[p]<='9'){
                    p++;
                    }
            }while(p!=8);
    pos=nbetud(matcin);
    for(j=0;j<8;j++)
        {
            matcin[pos][j]=ch[j];
        }

    }
//remplissage matrice nom
/*int vide(char ch[8]){
    int i,nb=0;
    for (i=0;i<strlen(ch)-1;i++){
        if (ch[i]=="");
            nb++;
    }
    if (nb>1){
        return 1;
        }
    else {
    return 0;
    }

}*/
int nbch(char ch[20]){
    int i,n=0;
    for (i=0;i<20;i++){
        if (ch[i]-32>='A' && ch[i]-32<='Z')
            n++;
    }
    return n;
}
void remplirmatnom(char matnom[100][20],char matcin[100][8]){
    int i,j,p;
    int pos,n;
    pos=nbetud(matcin);
    char ch[8],ch1[8];
            do{
            printf("Entrez le nom de l'etudiant : ");
            fflush(stdin);
            gets(ch);
            fflush(stdin);
            p=0;
            while( p<strlen(ch) && ch[p]>='A' && ch[p]<='Z' || ch[p]>='a' && ch[p]<='z' ){
                    p++;
                    }
            }while(p<strlen(ch));
            for (int k=0;k<strlen(ch);k++){
                    matnom[pos-1][k]=ch[k];
                    }
                }
//remplissage matrice prenom
void remplirmatpnom(char matpnom[100][20],char matcin[100][8]){
    int i,j,p;
    int pos;
    pos=nbetud(matcin);
    char ch[8],ch1[8];
            do{
            printf("Entrez le prenom de l'etudiant : ");
            gets(ch);
            fflush(stdin);
            p=0;
            while(p<strlen(ch) && ch[p]>='A' && ch[p]<='Z' || ch[p]>='a' && ch[p]<='z' ){
                    p++;}
            }while(p<strlen(ch));
            for (int k=0;k<strlen(ch);k++){
                    matpnom[pos-1][k]=ch[k];
                    }
                }

// remplissage tableau absence
void remplirtababs(int tab_nbabs[100],char matcin[100][8]){
    int i=0;
    int x;
    int pos=nbetud(matcin);
        do{
            printf("entrez le nombre d'absence de l'etudiant\n");
            scanf("%i",&x);
        }while (x<0 || x>20);
        tab_nbabs[pos-1]=x;

    }


//remplissage matrice specialité et tableau groupe 1,2,3
void remplirmatspec_tabgrp(char matspec[100][9], int tab_grp[100],char matcin[100][8]){
    int pos;
    pos=nbetud(matcin);
    int j=0;
    int i=0;
    int g;
    char ch3[2];

    char ch[9];
            do{
            printf("Entrez la specialite de l'etudiant: ");
            fflush(stdin);
            gets(ch);
        }while (!( strcmp(ch,"LNIG-BI")==0) && !(strcmp(ch,"LNIG-BIS")==0));

        for(j=0;j<strlen(ch);j++)
            matspec[pos-1][j]=ch[j];


      do{

            printf("Entrez le groupe de l'etudiant: ");
            fflush(stdin);
            gets(ch3);
            g = atoi(ch3);
            }while((g!=1 && g!=2 && g!=3 && strcmp(ch,"LNIG-BI")==0)||(g!=1 && g!=2 && strcmp(ch,"LNIG-BIS")==0));
            tab_grp[pos-1]=g;
}

void addNewStudent(char matcin[100][8],char matnom[100][20],char matpnom[100][20],char matspec[100][9],int tab_grp[100],int tab_abs[100])
{
    int i,j;
    remplirmatcin(matcin);
    printf("\n");
    remplirmatnom(matnom,matcin);
    printf("\n");
    remplirmatpnom(matpnom,matcin);
    printf("\n");
    remplirtababs(tab_abs,matcin);
    printf("\n");
    remplirmatspec_tabgrp(matspec,tab_grp,matcin);
    printf("\n");

    }


void affiche_tout(char matcin[100][8],char matnom[100][20],char matpnom[100][20],char matspec[100][9],int tab_grp[100],int tab_abs[100])
{ int pos;
        pos=nbetud(matcin);
        printf("Cin:\n");
    for (int i=0;i<pos;i++){
        for (int j=0;j<8;j++)
            printf("%c",matcin[i][j]);
        printf("\n");

        }
        printf("Nom:\n");
        for (int i=0;i<pos;i++){
        for (int j=0;j<8;j++)
            printf("%c",matnom[i][j]);
        printf("\n");

        }
        printf("Prenom:\n");
        for (int i=0;i<pos;i++){
        for (int j=0;j<8;j++)
            printf(" %c",matpnom[i][j]);
        printf("\n");

        }
        printf("Absences:\n");
        for (int i=0;i<pos;i++)
            printf("%d\t",tab_abs[i]);
        printf("\n");
        printf("Specialite:\n");
        for (int i=0;i<pos;i++){
        for (int j=0;j<9;j++){
            printf("%c",matspec[i][j]);}
        printf("\n");}

        printf("Groupe:\n");
        for (int i=0;i<pos;i++)
            printf("%d\n",tab_grp[i]);
        printf("\n");



   }



void supprimer(char matcin[100][8],char matnom[100][20],char matpnom[100][20], char matspec[100][9],int tab_grp[100], int tab_abs[100])
{
	    int pos=nbetud(matcin);
		int i,j,p, c = 0,possupp=-1;
		char cin[8],ch[8];
		printf("Saisir la cin de l'etudiant: ");
		fflush(stdin);
		gets(cin);


       for (i=0;i<100;i++){
            for (j=0;j<8;j++){
                    ch[j]=matcin[i][j];
                }

                int c=0;
                for(int k=0;k<8;k++)
                    if(ch[k]==cin[k])
                        c++;
                if (c==8){
                    possupp=i;

                }
              if(possupp!=-1)
                    break;
            }
printf("%d----------\n",possupp);

		if (possupp!=-1){
		//supprimer cin
        for(int k=possupp; k<pos; k++)
            for (j=0;j<8;j++)
                matcin[k][j] = matcin[k+1][j];
        for (int j=0;j<8;j++)
            matcin[pos-1][j]='0';
		//supprimer nom
        for(int k=possupp; k<pos; k++)
            for (j=0;j<20;j++)
                matnom[k][j] = matnom[k+1][j];
        for (int j=0;j<20;j++)
            matnom[pos-1][j]=' ';
		//supprimer prenom
        for(int k=possupp; k<pos; k++)
            for (j=0;j<20;j++)
                matpnom[k][j] = matpnom[k+1][j];
        for (int j=0;j<20;j++)
            matpnom[pos-1][j]=' ';
		//supprimer specialité
        for(int k=possupp; k<pos; k++)
            for (j=0;j<9;j++)
                matspec[k][j] = matspec[k+1][j];
        for (int j=0;j<9;j++)
            matspec[pos-1][j]=' ';
        for (int k=possupp;k<pos;k++)
            tab_abs[k]=tab_abs[k+1];
        tab_abs[pos-1]=0;
        for (int k=possupp;k<pos;k++)
            tab_grp[k]=tab_grp[k+1];
        tab_grp[pos-1]=0;

        printf("\nL'etudiant %s a ete supprime avec succes.\n\n", cin);
		}
        else{
            printf("\nCIN introuvable.\n");
            }


affiche_tout(matcin,matnom,matpnom,matspec,tab_grp,tab_abs);


}








void modifier(char matcin[100][8],char matnom[100][20],char matpnom[100][20], char matspec[100][9],int tab_grp[100], int tab_abs[100])
	{
        int i,j,pos;
        pos=nbetud(matcin);
		int ps,rep, c = 0;
		char cin[8],ch[8],ch2[20];
		printf("Saisir la cin de l'etudiant: ");
		fflush(stdin);
		gets(cin);
		ps=-1;
		for(i=0;i<pos;i++){
                for (j=0;j<8;j++)
                   {ch[j]=matcin[i][j];}
                c=0;
                while(c<8 && ch[c]==cin[c])
                    {c++;}
                    if(c==8){
                    ps=i;
                    printf("Position : %d----\n",ps);
                    }
            }


				    if(ps!=-1){
					printf("\nQuel information souhaitez-vous modifier?\n1.CIN\n2.NOM\n3.PRENOM\n4.SPECIALITE\n5.GROUPE\n6.NOMBRE D'ABSENCE\n: ");
                    scanf("%i",&rep);
                    fflush(stdin);
                    if (rep==1){
					printf("\nEntrer la nouvelle cin:\n ");
					fflush(stdin);
					gets(ch2);

					for(i=0;i<8;i++){
                        matcin[ps][i]=ch2[i];

					}


					}
                    else if (rep==2){
                    printf("\nEntrer Le Nom:\n ");
					fflush(stdin);
					gets(ch2);
					for(i=0;i<20;i++){
                        matnom[ps][i]=ch2[i];

					}

					}
                    else if (rep==3){
                    printf("\nEntrer Le Prenom:\n ");

					fflush(stdin);
					gets(ch2);
					for(i=0;i<20;i++){
                        matpnom[ps][i]=ch2[i];

					}
					}
                    else if (rep==4){
                    printf("\nEntrer La nouvelle spécialité:\n ");

                    fflush(stdin);
					gets(ch2);
					for(i=0;i<9;i++){
                        matspec[ps][i]=ch2[i];

					}

					}
                    else if (rep==5){
                    printf("\nEntrer Le nouveau Groupe:\n ");
					scanf("%i",&tab_grp[ps]);
					}
                    else{
                    printf("\nEntrer Le nouveau nombre d'absence:\n ");
					scanf("%d",&tab_abs[ps]);
					}
					printf("\n");
					affiche_tout(matcin,matnom,matpnom,matspec,tab_grp,tab_abs);

                    }
                    else{
                        printf("\nMatricule introuvable.\n\n");}
	}
	/*
void taux (int tab_abs[100],char matcin[100][8], char matspec[100][9]){
                int s1,s2,m1,m2,x,pos;
                pos=nbetud(matcin);
                float p1,p2;
                for (int i=0;i<pos;i++){
                if(matspec[i]=="LNIG-BI"){
                    s1=s1+tab_abs[i];}
                else{
                    s2=s2+tab_abs[i];
                }
                }
                m1=s1*5;
                m2=s2*5;
                x=24*7*(pos-1);
                p1=(m1/s1)*100;
                p2=(m2/s2)*100;
                printf("Le taux d'absenteisme des etudiants de la specialite LNIG-BI est %f ",p1);
                printf("Le taux d'absenteisme des etudiants de la specialite LNIG-BIS est %f ",p2);
                }*/
 void affichespec(char matcin[100][8],char matnom[100][20],char matpnom[100][20], char matspec[100][9],int tab_grp[100],int tab_abs[100]){
        int pos=nbetud(matcin);
        int r;
		int i,j,p, c = 0,possupp=-1;
		char bi[8]="LNIG-BI";
        char bis[9]="LNIG-BIS";
        char ch[8];
        char ch2[8];
       for (i=0;i<100;i++){
            for (j=0;j<8;j++){
                    ch[j]=matspec[i][j];
                }

                int c=0;
                for(int k=0;k<8;k++)
                    if(ch[k]==bi[k])
                        c++;
                if (c==8){
                    printf("SPECIALITE: LNIG-BI\n");
                    printf("CIN:\t");
                    for (int j=0;j<8;j++)
                        printf("%c",matcin[i][j]);
                        printf("\n");
                    printf("NOM:\t");
                    for (int j=0;j<8;j++)
                        printf("%c",matnom[i][j]);
                        printf("\n");
                }
              if(possupp!=-1)
                    break;
            }
        for (i=0;i<100;i++){
            for (j=0;j<8;j++){
                    ch2[j]=matspec[i][j];
                }

                int c=0;
                for(int k=0;k<8;k++)
                    if(ch2[k]==bis[k])
                        c++;
                if (c==8){
                    printf("SPECIALITE: LNIG-BIS\n");
                    printf("CIN:\t");
                    for (int j=0;j<8;j++)
                        printf("%c",matcin[i][j]);
                        printf("\n");
                    printf("NOM:\t");
                    for (int j=0;j<8;j++)
                        printf("%c",matnom[i][j]);
                        printf("\n");
                }
              if(possupp!=-1)
                    break;
            }
        printf("Retour au menu? \n 1.OUI\n 2.NON\n");
        scanf("%i",&r);
        if (r==1){
        menu_ques(matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
        }
            }

int maximum(int un,int d,int t){
    int m;
    if(un >= d && un >= t){
		m=un;
		printf("Groupe 1: %i etudiants\n",un);
	}
	else if(d >= un && d >= t){
		m=d;
		printf(" Groupe 2: %i etudiants\n",d);
	}
	else {
		m=t;
		printf("Groupe 3: %i etudiants\n",t);
	}
	return m;

}




void affichepar(char matcin[100][8],char matnom[100][20],char matpnom[100][20], char matspec[100][9],int tab_grp[100],int tab_abs[100]){
        int pos=nbetud(matcin);
		int i,j,p, c = 0,possupp=-1;
		int r;
		char bi[8]="LNIG-BI";
        char bis[9]="LNIG-BIS";
        char ch[8];
        char ch2[8];
        int b=0,bs=0,un=0,d=0,t=0;
       for (i=0;i<100;i++){
            for (j=0;j<8;j++){
                    ch[j]=matspec[i][j];
                }

                int c=0;
                for(int k=0;k<8;k++)
                    if(ch[k]==bi[k])
                        c++;
                if (c==8){
                    b++;
                }
              if(possupp!=-1)
                    break;
            }
            printf("SPECIALITE: LNIG-BI: %i\n",b);
        for (i=0;i<100;i++){
            for (j=0;j<8;j++){
                    ch2[j]=matspec[i][j];
                }

                int c=0;
                for(int k=0;k<8;k++)
                    if(ch2[k]==bis[k])
                        c++;
                if (c==8){
                    bs++;
                }
              if(possupp!=-1)
                    break;
            }
            printf("SPECIALITE: LNIG-BIS: %i\n",bs);
        for (i=0;i<100;i++){
            if (tab_grp[i]==1){
                un++;
            }
            else if (tab_grp[i]==2){
                d++;
            }
            else if (tab_grp[i]==3){
                t++;
            }
        }
        printf("Groupe 1:  %i\n",un);
        printf("Groupe 2:  %i\n",d);
        printf("Groupe 3:  %i\n",t);
        printf("Retour au menu? \n 1.OUI\n 2.NON\n");
        scanf("%i",&r);
        if (r==1){
        menu_ques(matcin,matnom,matpnom,matspec,tab_grp,tab_abs,tab_grp);
        }
            }
void lemaxdumin(char matcin[100][8],char matnom[100][20],char matpnom[100][20], char matspec[100][9],int tab_grp[100],int tab_abs[100]){
        int pos=nbetud(matcin);
		int i,j,p, c = 0,possupp=-1;
		int r;
		char bi[8]="LNIG-BI";
        char bis[9]="LNIG-BIS";
        char ch[8];
        char ch2[8];
        int b=0,bs=0,un=0,d=0,t=0;
       for (i=0;i<100;i++){
            for (j=0;j<8;j++){
                    ch[j]=matspec[i][j];
                }

                int c=0;
                for(int k=0;k<8;k++)
                    if(ch[k]==bi[k])
                        c++;
                if (c==8){
                    b++;
                    //printf("%i",b);
                }
              if(possupp!=-1)
                    break;
            }
        for (i=0;i<100;i++){
            for (j=0;j<8;j++){
                    ch2[j]=matspec[i][j];
                }

                int c=0;
                for(int k=0;k<8;k++)
                    if(ch2[k]==bis[k])
                        c++;
                if (c==8){
                    bs++;
                    //printf("%i",bs);
                }
              if(possupp!=-1)
                    break;
            }
        for (i=0;i<100;i++){
            if (tab_grp[i]==1){
                un++;
            }
            else if (tab_grp[i]==2){
                d++;
            }
            else if (tab_grp[i]==3){
                t++;
            }
        }

        if(b<bs){
            printf("La specialite qui contient le moins d etudiant: LNIG-BI\n");
            printf("Le groupe qui contient le plus d etudiant:\n");
            maximum(un,d,t);
        }
        else if (bs<b){
            printf("La specialite qui contient le moins d etudiant: LNIG-BIS\n");
            printf("Le groupe qui contient le plus d etudiant:\n");
            if (un>d){
                 printf("Groupe 1: %i etudiants\n",un);
            }
            else{
                printf("Groupe 1: %i etudiants\n",d);
            }
        }
        printf("Retour au menu? \n 1.OUI\n 2.NON\n");
        scanf("%i",&r);
        if (r==1){
        menu_ques(matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
        }
        }

void lettre(char matcin[100][8],char matnom[100][20],char matpnom[100][20], char matspec[100][9],int tab_grp[100],int tab_abs[100]){
        int pos=nbetud(matcin);
        int r;
        //int tr=0;
		int i,j,p, c = 0,possupp=-1;
		char bi[8]="LNIG-BI";
        char bis[9]="LNIG-BIS";
        char ch[8];
        char x[2];
        char ch2[8];
        int k;
        printf("Donner une lettre: \n");
        fflush(stdin);
        gets(x);
        printf("Votre Lettre:%c\n",x[0]);
       for (i=0;i<100;i++){
            for (j=0;j<8;j++){
                    ch[j]=matspec[i][j];
                }

                int c=0;
                for(k=0;k<8;k++)
                    if(ch[k]==bi[k])
                        c++;
                if (c==8){
                    if (matnom[i][0]==x[0]){
                    printf("SPECIALITE: LNIG-BI\n");
                    printf("NOM:\t");
                    //for (k=i;k<pos;k++){
                       // if (matnom[i][0]==x[0]){
                            for (int j=0;j<20;j++){
                                printf("%c",matnom[i][j]);}
                        printf("\n");
                       // }
                        //}
                }
                }
              if(possupp!=-1)
                    break;

            }
        for (i=0;i<100;i++){
            for (j=0;j<8;j++){
                    ch2[j]=matspec[i][j];
                }

                int c=0;
                for(k=0;k<8;k++)
                    if(ch2[k]==bis[k])
                        c++;
                if (c==8){
                    if (matnom[i][0]==x[0]){
                    printf("SPECIALITE: LNIG-BIS\n");
                    printf("NOM:\t");
                    //for (k=i;k<pos;k++){
                        //if (matnom[i][0]==x[0]){
                            for (int j=0;j<20;j++){
                                printf("%c",matnom[i][j]);}
                        printf("\n");//}
                       // }
                }}
              if(possupp!=-1)
                    break;
            }
       /* printf("Retour au menu? \n 1.OUI\n 2.NON\n");
        scanf("%i",&r);
        if (r==1){
        menu(matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
        }*/
        printf("Retour au menu? \n 1.OUI\n 2.NON\n");
        scanf("%i",&r);
        if (r==1){
        menu_ques(matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
        }
            }
void supabs(char matcin[100][8],char matnom[100][20],char matpnom[100][20], char matspec[100][9],int tab_grp[100],int tab_abs[100]){
int i,pos,posi,j,r,k;
int tr=1;
pos=nbetud(matcin);
for (i=0;i<pos;i++){
    if (tab_abs[i]==20){
           // printf("%i",i);
            posi=i;
    //if (posi!=-1){
    		//supprimer cin
        for(int k=posi; k<pos; k++)
            for (j=0;j<8;j++)
                matcin[k][j] = matcin[k+1][j];
        for (int j=0;j<8;j++)
            matcin[pos-1][j]='0';
		//supprimer nom
        for(int k=posi; k<pos; k++)
            for (j=0;j<20;j++)
                matnom[k][j] = matnom[k+1][j];
        for (int j=0;j<20;j++)
            matnom[pos-1][j]=' ';
		//supprimer prenom
        for(int k=posi; k<pos; k++)
            for (j=0;j<20;j++)
                matpnom[k][j] = matpnom[k+1][j];
        for (int j=0;j<20;j++)
            matpnom[pos-1][j]=' ';
		//supprimer specialité
        for(int k=posi; k<pos; k++)
            for (j=0;j<9;j++)
                matspec[k][j] = matspec[k+1][j];
        for (int j=0;j<9;j++)
            matspec[pos-1][j]=' ';
        for (int k=posi;k<pos;k++)
            tab_abs[k]=tab_abs[k+1];
        tab_abs[pos-1]=0;
        for (int k=posi;k<pos;k++)
            tab_grp[k]=tab_grp[k+1];
        tab_grp[pos-1]=0;
        tr++;
    }}
    if (tr!=1){
        printf("\n %i etudiant a ete supprime avec succes.\n\n",tr);
    }
    else if (tr==1){
            printf("\nPersonne n est eliminee\n");}
    printf("Retour au menu? \n 1.OUI\n 2.NON\n");
    scanf("%i",&r);
    if (r==1){
    menu_ques(matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
        }
    }

        /*for (int k=i;k<pos;k++){
            tab_abs[k]=tab_abs[k+1];
            tab_abs[pos-1]=0;}*/


void elimine(char matcin[100][8],char matnom[100][20],char matpnom[100][20], char matspec[100][9],int tab_grp[100],int tab_abs[100]){
    int i,pos,posi,j,r,k;
    int tr=1;
    pos=nbetud(matcin);
    for (i=0;i<pos;i++){
        if (tab_abs[i]>=6){
            posi=i;
            printf("NOM:\t");
           // for (int i=posi;i<pos;i++){
                for (int j=0;j<8;j++)
                    printf("%c",matnom[posi][j]);
                printf("\n");

                    //}
            printf("PRENOM:\t");
           // for (int i=posi;i<pos;i++){
                for (int j=0;j<8;j++)
                    printf("%c",matpnom[posi][j]);
                printf("\n");
                //}
            tr++;
        }
    }
    if (tr==1){
        printf("personne n est elimine\n");
    }
        printf("Retour au menu? \n 1.OUI\n 2.NON\n");
        scanf("%i",&r);
        if (r==1){
        menu_ques(matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
        }
}
void assidu(char matcin[100][8],char matnom[100][20],char matpnom[100][20], char matspec[100][9],int tab_grp[100],int tab_abs[100]){
    int i,pos,posi,j,r,k;
    int tr=1;
    pos=nbetud(matcin);
    for (i=0;i<pos;i++){
        if (tab_abs[i]==0){
            posi=i;
            printf("NOM:\t");
           // for (int i=posi;i<pos;i++){
                for (int j=0;j<8;j++)
                    printf("%c",matnom[posi][j]);
                printf("\n");

                    //}
            printf("PRENOM:\t");
           // for (int i=posi;i<pos;i++){
                for (int j=0;j<8;j++)
                    printf("%c",matpnom[posi][j]);
                printf("\n");
                //}
            tr++;
        }
    }
    if (tr==1){
        printf("personne n est assidu\n");
    }
        printf("Retour au menu? \n 1.OUI\n 2.NON\n");
        scanf("%i",&r);
        if (r==1){
        menu_ques(matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
        }
}



 void menu_ques(char matcin[100][8],char matnom[100][20],char matpnom[100][20], char matspec[100][9],int tab_grp[100], int tab_abs[100]){
    //char option[3] = "NON";
    int quitter;
    //while((strcmp(option, "OUI") !=0) && (strcmp(option, "oui") !=0)){  //while pour repéter le menu tant que l'utilisateur n'entre pas OUI ou oui
        int choixMenu;
        printf("\n\n**************************** Questions ****************************\n\n");
        printf("1- Donner la liste des etudiants de la specialite LNIG-BI ainsi que celle de la specialite LNIG-BIS separement. \n");
        printf("2- Afficher le nombre des etudiants par groupe et spécialite. \n");
        printf("3- Donner le groupe qui contient le plus d etudiants dans la specialite qui contient le moins d etudiants.\n");
        printf("4- Afficher la liste des etudiants dont le nom commence par une lettre donnee\n");
        printf("5- Supprimer les etudiants qui n on jamais assiste.\n");
        printf("6- Afficher les etudiants elimine.\n");
        printf("7- Taux d'absenteisme.\n");
        printf("8- Afficher les etudiants assidus\n");
        printf("0- Retour au menu principal\n");
        printf("Veuillez enter votre choix :\t");
        scanf("%d", &choixMenu);
        printf("\n");

        switch(choixMenu)
        {
            case 0:
                menu(matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
                break;
            case 1:
                affichespec(matcin,matnom,matpnom,matspec,tab_grp,tab_abs);

                break;
            case 2:
                affichepar(matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
                break;
            case 3:
                lemaxdumin(matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
                break;
            case 4:
                lettre(matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
                break;
            case 5:
                supabs(matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
                break;
            case 6:
                elimine(matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
                break;
            case 8:
                assidu(matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
                break;
                float taux;
                int s=0;
                //int nb=7; //nb de seances
            case 7:
                for (int i=0;i<100;i++){
                    s=s+tab_abs[i];
                }
                printf("%i total absences\n",s);
                taux=((s/7)*100)/100;
                printf("Le taux d'absenteisme est %.2f \n",taux);
                menu_ques(matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
                break;

          /* case 2:
                eliminer(matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
                break;
            case 3:
                assidu(matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
                break;
            case 4:
                listspec(matcin,matnom,matpnom,matspec);
                break;
            case 5:
                nbetudiant(matspec,tab_grp);
                break;
            case 6:
                maxetud(matspec,tab_grp);
                break;
            case 7:
                exlettre(matcin,matnom,matpnom,matspec);
                break;
            case 8:
                maxlettre(matcin,matnom,matpnom);
                break;

                }
*/
    }}

 void menu(char matcin[100][8],char matnom[100][20],char matpnom[100][20], char matspec[100][9],int tab_grp[100], int tab_abs[100]){
    //char option[3] = "NON";
    int quitter;
    //while((strcmp(option, "OUI") !=0) && (strcmp(option, "oui") !=0)){  //while pour repéter le menu tant que l'utilisateur n'entre pas OUI ou oui
        int choixMenu;
        printf("\n\n**************************** MENU ****************************\n\n");
        printf("1 - Ajouter un etudiant.\n");
        printf("2 - Modifier un etudiant.\n");
        printf("3 - Supprimer un etudiant.\n");
        printf("4 - Rechercher un etudiant.\n");
        printf("5 - Questions Independantes.\n");
        printf("6 - Menu Partie 2\n");
        printf("7 - Quitter le programme.\n ");
        printf("Entrez votre choix:\t");
        scanf("%d", &choixMenu);
        printf("\n");

        switch(choixMenu)
        {
            case 1:
                printf("\n**************************** Ajout etudiant ****************************\n\n");
                addNewStudent(matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
                menu(matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
                break;
           case 2:
                modifier(matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
                menu(matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
                break;
            case 3:
                supprimer(matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
                menu(matcin,matnom,matpnom,matspec,tab_grp,tab_abs);

                break;
            case 4:
                recherche(matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
                menu(matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
                break;
            case 5:
                menu_ques(matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
                break;
            case 6:
                main();
            break;
            case 7:
                printf("VOUS ALLEZ QUITTER LE PROGRAMME , etes vous sur? \n 1.OUI\n 2.NON\n");
                scanf("%d",&quitter);
                if (quitter==2){
                    menu(matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
                }
                break;

    }

    printf("\nMerci d'avoir utiliser notre mini-programme. A la prochaine! :)\n");
    printf("\n  **************************** Fin ****************************\n\n");
}






int main()
{
    //note_assidu[100],float note_projet[100],float note_exam[100],float note_assidu_bis[100],float note_projet_bis[100],float note_ds[100],int cinetud[100],int cinetud2[100],float moy_asd[100] ){
    float note_assidu[100]={0};
    float moy_asd[100]={0};
    float moy_asd_bis[100]={0};
    float note_projet[100]={0.00};
    float note_exam[100]={0};
    float note_assidu_bis[100]={0};
    float note_projet_bis[100]={0.00};
    float note_ds[100]={0};
    int cinetud[100]={0};
    int cinetud2[100]={0};
    int i;
    int pos;
    char matcin[100][8]={"11211130","11112345","12345679","44441234"};
    for (int i=4;i<100;i++)
        for (int j=0;j<8;j++)
            matcin[i][j]='0';

    char matnom[100][20]={"AAA","BBB","CCC","DDD"};
    for (int i=4;i<100;i++)
        for (int j=0;j<20;j++)
            matnom[i][j]=' ';

    char matpnom[100][20]={"ALI","AHMED","SARRA","KENZA"};
    for (int i=4;i<100;i++)
        for (int j=0;j<20;j++)
            matpnom[i][j]=' ';

    char matspec[100][9]={"LNIG-BI","LNIG-BI","LNIG-BI","LNIG-BIS"};
    for (int i=4;i<100;i++)
        for (int j=0;j<20;j++)
            matspec[i][j]=' ';

    int tab_abs[100]={1,0,6,20};
    for (int i=4;i<100;i++)
            tab_abs[i]=0;

    int tab_grp[100]={1,1,1,2};
    for (int i=4;i<100;i++)
            tab_grp[i]=0;



    int choix;
    system("COLOR B0");
    printf(" \n\n\n\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *");
		printf("\n\n\t\t\t\t\t     *                    *");
		printf("\n\n\t\t\t\t\t     *      BIENVENUE     *");
		printf("\n\n\t\t\t\t\t     *                    *");
		printf("\n\n\t\t\t\t\t     *  *  *  *  *  *  *  *");
		printf("\n\n\t\t\t\t             Projet ASD 2022-2023");
    printf("\n\n\t\t\t La Gestion des etudiants de 3eme annees LNIG-BI & LNIG-BIS");
    printf("\n\n\t\t\t Appuyer sur Entrer pour continuer...\n\t\t\t");
    getch();
    printf("Souhaitez-vous acceder a la Partie 1 ou a la Partie 2?\n\t\t\t");
    printf("Veuillez entrer 1 ou 2\n\t\t\t");
    scanf("%d",&choix);
    switch(choix)
        {
            case 1:
                menu(matcin,matnom,matpnom,matspec,tab_grp,tab_abs);

               // addNewStudent(matcin,matnom,matpnom,matspec,tab_grp,tab_abs);

            break;
            case 2:
                menu22(note_assidu,note_projet,note_exam,note_assidu_bis,note_projet_bis,note_ds,cinetud,cinetud2,moy_asd,moy_asd_bis,matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
            break;
                //L'appel de cette fonction lancera le 1er menu
                //L'appel de cette fonction lancera le 2eme menu

        }

    printf("__________________  Au revoir!  __________________ \n\n");
    return 0;
}
/*
int verif(int cin,char matcin[100][8]){
    int ps,i,j,c,pos;
    pos=nbetud(matcin);
    char cin1[8];
    itoa(cin,cin1,10);
    char ch[8];
    ps=-1;
		for(i=0;i<pos;i++){
                for (j=0;j<8;j++)
                   {ch[j]=matcin[i][j];}
                c=0;
                while(c<8 && ch[c]==cin1[c])
                    {c++;}
                    if(c==8){
                    ps=i;
                    }
            }
    return ps;
    }
    /*
    itoa(cin,cin1,10);
    for(g=0;g<pos;g++){
        for (p=0;p<8;p++)
            {new1[g]=matcin[g][p];}
            printf("%s",new1[g]);
            c=0;
            while(c<8 && cin1[c]==new1[c])
            {c++;}
    }
        }while(c!=8);*/


void remplirnote(char matcin[100][8],char matnom[100][20],char matpnom[100][20], char matspec[100][9],int tab_grp[100], int tab_abs[100]){
    //int cin;
    int possupp;
    int choice;
    int n;
    int r;
    float note;
    float note_assidu[100]={0};
    float moy_asd[100]={0};
    float note_projet[100]={0.00};
    float note_exam[100]={0};
    float note_assidu_bis[100]={0};
    float note_projet_bis[100]={0.00};
    float note_ds[100]={0};
    int cinetud[100]={0};
    int cinetud2[100]={0};
    int e;
    do{
    printf("Combien d'etudiant?\n");
    scanf("%i",&e);
    }while (e<0 || e>100);
    int o=1;
    char ch[9];
    char ch2[8];
    int i=0;
    int w=0;
    int z=0;
    int j=0;
    int q=0;
    int k=0;
    int g=0;
    int p=0;
    int c=0;
    char cin[8];
    char new1[8];
    int ps;
    int pos;
    int posi;
    pos=nbetud(matcin);
    do{
    printf("Quel Note souhaitez vous entrer?\n 1.Assiduite \n 2.Projet \n 3.Examen/DS\n");
    scanf("%i",&choice);
    //int pos=nbetud(matcin);
    int i,j,p, c = 0,possupp=-1;
    char cin[8],ch[8],ch5[9],ch6[9],ch7[9];
    switch (choice){
            case 1:
                do{
                    printf("Entrez la specialite de l'etudiant %i: ",q+1);
                    fflush(stdin);
                    gets(ch5);
                    }while (!( strcmp(ch5,"LNIG-BI")==0) && !(strcmp(ch5,"LNIG-BIS")==0));
                do{

                printf("Saisir la cin de l'etudiant: ");
                fflush(stdin);
                gets(cin);


               for (i=0;i<100;i++){
                    for (j=0;j<8;j++){
                            ch[j]=matcin[i][j];
                        }

                    int c=0;
                    for(int k=0;k<8;k++){
                        if(ch[k]==cin[k])
                            c++;
                    }
                    if (c==8){
                        possupp=i;

                    }
                  if(possupp!=-1)
                    break;
                }
               // printf("%d----------\n",possupp);

            if (possupp!=-1){
            printf("CIN correct\n");
            }
        else {
            printf("CIN INTROUVABLE\n");
        }
                }while(possupp==-1);
                int v;

                /*sscanf(cin,"%d",&x);
                printf("\n%d  YOOOOO its int now.\n",x);*/
                    do{
                    printf("Veuillez entrer la note de l'Assiduite\n");
                    scanf("%f",&note);
                    }while(note<0 || note>20);
                //posi=nbetud(cinetud);
                //int x;
                    int x;
                    char* cin2=cin;
                    //printf("%s cin2\n",cin2);
                    sscanf(cin2,"%d",&x);
                    //printf("\n%d  YOOOOO its int now.\n",x);
                    if (strcmp(ch5,"LNIG-BI")==0){
                    cinetud[q]=x;
                    printf("CIN:%d\n",cinetud[q]);
                    note_assidu[q]=note;
                    printf("%f\n",note_assidu[q]);
                    q++;

                }
                else {
                    cinetud2[q]=x;
                    printf("CIN:%d\n",cinetud2[q]);

                    note_assidu_bis[q]=note;
                    printf("%f\n",note_assidu_bis[q]);
                    q++;
                }

            break;
    case 2:
            do{
                    printf("Entrez la specialite de l'etudiant %i: ",w+1);
                    fflush(stdin);
                    gets(ch6);
                    }while (!( strcmp(ch6,"LNIG-BI")==0) && !(strcmp(ch6,"LNIG-BIS")==0));
                do{

                printf("Saisir la cin de l'etudiant: ");
                fflush(stdin);
                gets(cin);


               for (i=0;i<100;i++){
                    for (int k=0;k<8;k++){
                            ch[k]=matcin[i][k];
                        }

                    int c=0;
                    for(int k=0;k<8;k++){
                        if(ch[k]==cin[k])
                            c++;
                    }
                    if (c==8){
                        possupp=j;

                    }
                  if(possupp!=-1)
                    break;
                }
               // printf("%d----------\n",possupp);

            if (possupp!=-1){
            printf("CIN correct\n");
            }
        else {
            printf("CIN INTROUVABLE\n");
        }
                }while(possupp==-1);
                    do{
                    printf("Veuillez entrer la note du projet\n");
                    scanf("%f",&note);
                    }while(note<0 || note>20);

                    int x1;
                    char* cin3=cin;
                    //printf("%s\n",cin3);
                    sscanf(cin3,"%d",&x1);
                  //  printf("\n%d  YOOOOO its int now.\n",x1);
                    if (strcmp(ch6,"LNIG-BI")==0){
                    cinetud[w]=x1;
                    printf("CIN:%d\n",cinetud[w]);
                    note_projet[w]=note;
                    printf("%f\n",note_projet[w]);
                    w++;

                }
                else {
                    cinetud2[w]=x1;
                    printf("CIN:%d\n",cinetud2[w]);

                    note_projet_bis[w]=note;
                    printf("%f\n",note_projet_bis[w]);
                    w++;
                }
        break;

case 3:
            //do{
               do{
                    printf("Entrez la specialite de l'etudiant %i: ",z+1);
                    fflush(stdin);
                    gets(ch7);
                    }while (!( strcmp(ch7,"LNIG-BI")==0) && !(strcmp(ch7,"LNIG-BIS")==0));
                do{

                printf("Saisir la cin de l'etudiant: ");
                fflush(stdin);
                gets(cin);


               for (i=0;i<100;i++){
                    for (j=0;j<8;j++){
                            ch[j]=matcin[i][j];
                        }

                    int c=0;
                    for(int k=0;k<8;k++){
                        if(ch[k]==cin[k])
                            c++;
                    }
                    if (c==8){
                        possupp=z;

                    }
                  if(possupp!=-1)
                    break;
                }
                //printf("%d----------\n",possupp);

            if (possupp!=-1){
            printf("CIN correct\n");
            }
        else {
            printf("CIN INTROUVABLE\n");
        }
                }while(possupp==-1);
                    do{
                    printf("Veuillez entrer la note de l'Exam/DS\n");
                    scanf("%f",&note);
                    }while(note<0 || note>20);


                    int x2;
                    char* cin4=cin;
                    //printf("%s\n",cin3);
                    sscanf(cin4,"%d",&x2);
                  //  printf("\n%d  YOOOOO its int now.\n",x1);
                    if (strcmp(ch7,"LNIG-BI")==0){
                    cinetud[z]=x2;
                    printf("CIN:%d\n",cinetud[z]);
                    note_exam[z]=note;
                    printf("%f\n",note_exam[z]);
                    z++;

                }
                else {
                    cinetud2[z]=x2;
                    printf("CIN:%d\n",cinetud2[z]);

                    note_ds[z]=note;
                    printf("%f\n",note_ds[z]);
                    z++;
                }

            break;
    }

    printf("Voulez-vous Continuer? Oui=1 Non=0?\n");
    scanf("%i",&o);
    }while(o==1);
    printf("Retour au menu? \n 1.OUI\n 2.NON\n");
    scanf("%i",&r);
    if (r==1){
    menu22(note_assidu,note_projet,note_exam,note_assidu_bis,note_projet_bis,note_ds,cinetud,cinetud2,moy_asd,matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
    }
        return pos;}


void moy(float moy_asd[100],float moy_asd_bis[100],float note_assidu[100],float note_projet[100], float note_exam[100],float note_assidu_bis[100],float note_projet_bis[100], float note_ds[100], int cinetud[100], int cinetud2[100],char matcin[100][8],char matnom[100][20],char matpnom[100][20], char matspec[100][9],int tab_grp[100], int tab_abs[100]){

        float moy;
        float moy2;
        int i=0;
        int r;
        int j=0;
       printf("LES ETUDIANTS DE LA SPECIALITE LNIG-BI\n");
        while(cinetud[i]!=0){
            moy=((note_assidu[i]*0.1)+(note_projet[i]*0.2)+(note_exam[i]*0.7));
            moy_asd[i]=moy;
            printf("CIN: %i MOYENNE: %f\n",cinetud[i],moy_asd[i]);
            i++;}

      /*printf("LES ETUDIANTS DE LA SPECIALITE LNIG-BIS\n");
        while(cinetud2[j]!=0){
            moy=((note_assidu_bis[j]*0.2)+(note_projet_bis[j]*0.4)+(note_ds[j]*0.4));
            moy_asd_bis[j]=moy;
            printf("CIN: %i MOYENNE: %f\n",cinetud2[j],moy_asd_bis[j]);
            i++;}*/
            /*i=0,moy=0;
            printf("LES ETUDIANTS DE LA SPECIALITE LNIG-BIS\n");
            while(cinetud2[i]!=0){
            moy=((note_assidu_bis[i]*0.2)+(note_projet_bis[i]*0.4)+(note_ds[i]*0.4));
            moy_asd_bis[i]=moy;
            printf("CIN: %i MOYENNE: %f\n",cinetud2[i],moy_asd_bis[i]);
            i++;}*/

        printf("LES ETUDIANTS DE LA SPECIALITE LNIG-BIS\n");
        while(cinetud2[j]!=0){
            moy2=((note_assidu_bis[j]*0.2)+(note_projet_bis[j]*0.4)+(note_ds[j]*0.4));
            moy_asd_bis[j]=moy2;
            printf("CIN: %i MOYENNE: %f\n",cinetud2[j],moy_asd_bis[j]);
            j++;}
        printf("Retour au menu? \n 1.OUI\n 2.NON\n");
        scanf("%i",&r);

        if (r==1){
         menu22(note_assidu,note_projet,note_exam,note_assidu_bis,note_projet_bis,note_ds,cinetud,cinetud2,moy_asd,matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
        }
}

void moyy(float moy_asd[100],float moy_asd_bis[100],float note_assidu[100],float note_projet[100], float note_exam[100],float note_assidu_bis[100],float note_projet_bis[100], float note_ds[100], int cinetud[100], int cinetud2[100],char matcin[100][8],char matnom[100][20],char matpnom[100][20], char matspec[100][9],int tab_grp[100], int tab_abs[100]){
    float maxi;
    int i=1,j,r;
    int pos;
    int pos2;
    maxi=moy_asd[0];
    while (cinetud[i]!=0)
            {
            if (moy_asd[i]>maxi){
                maxi=moy_asd[i];}
                pos=i;
            i++;

            }
            /*while (moy_asd_bis[j]!=0){
                if (moy_asd_bis[j]>maxx){
                maxx=moy_asd_bis[j];}
            j++;
            pos2=j;
            }
        if (maxi>maxx){
        printf("CIN %i\n",cinetud[pos]);*/
        printf("La meilleure moyenne est %f \n",maxi);
       /* else{
        printf("CIN %i\n",cinetud[pos]);
        printf("La meilleure moyenne est %f\t %f\n",maxx);

        }*/
         printf("Retour au menu? \n 1.OUI\n 2.NON\n");
        scanf("%i",&r);
        if (r==1){
         menu22(note_assidu,note_projet,note_exam,note_assidu_bis,note_projet_bis,note_ds,cinetud,cinetud2,moy_asd,matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
        }
}


int maxproj(float moy_asd[100],float moy_asd_bis[100],float note_assidu[100],float note_projet[100], float note_exam[100],float note_assidu_bis[100],float note_projet_bis[100], float note_ds[100], int cinetud[100], int cinetud2[100],char matcin[100][8],char matnom[100][20],char matpnom[100][20], char matspec[100][9],int tab_grp[100], int tab_abs[100]){
        float maxi;
        int i=1;
        int r;
        int pos;
        int pos2;
        int j=0;
        maxi=note_projet[0];
        while (cinetud[i]!=0)
            {
            if (note_projet[i]>maxi){
                maxi=note_projet[i];
                }
               // pos=i;
            i++;
            }
            printf("La meilleure note de projet est %f \n",maxi);

       /* else {
        printf("CIN %i\n",cinetud2[pos]);
        printf("La meilleure note de projet est %f\t %f\n",maxx);}*/
         printf("Retour au menu? \n 1.OUI\n 2.NON\n");
        scanf("%i",&r);
        if (r==1){
         menu22(note_assidu,note_projet,note_exam,note_assidu_bis,note_projet_bis,note_ds,cinetud,cinetud2,moy_asd,matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
        }

}
void nomoy(float moy_asd[100],float moy_asd_bis[100],float note_assidu[100],float note_projet[100],float note_exam[100],float note_assidu_bis[100],float note_projet_bis[100],float note_ds[100],int cinetud[100],int cinetud2[100],char matcin[100][8],char matnom[100][20],char matpnom[100][20], char matspec[100][9],int tab_grp[100], int tab_abs[100]){
            int i,r;
            int pos;
            printf("PAS LA MOYENNE:\n");
            while(cinetud[i]!=0){
                if (moy_asd[i]<10){
                    printf("CIN: %d MOY %f\n",cinetud[i],moy_asd[i]);
                    //pos=i;
                }
                i++;
            }
        printf("Retour au menu? \n 1.OUI\n 2.NON\n");
        scanf("%i",&r);
        if (r==1){
         menu22(note_assidu,note_projet,note_exam,note_assidu_bis,note_projet_bis,note_ds,cinetud,cinetud2,moy_asd,matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
        }
            }
void valider(float moy_asd[100],float moy_asd_bis[100],float note_assidu[100],float note_projet[100],float note_exam[100],float note_assidu_bis[100],float note_projet_bis[100],float note_ds[100],int cinetud[100],int cinetud2[100],char matcin[100][8],char matnom[100][20],char matpnom[100][20], char matspec[100][9],int tab_grp[100], int tab_abs[100]){
        int i,r;
        int pos;
        printf("VALIDE:\n");
    while(cinetud[i]!=0){
        if (moy_asd[i]>=10){
                //printf("ghjkl");
                printf("CIN: %d MOY %f\n",cinetud[i],moy_asd[i]);
       // pos=i;
        //printf("%i",pos);
                }
        i++;
            }

        printf("Retour au menu? \n 1.OUI\n 2.NON\n");
        scanf("%i",&r);
        if (r==1){
         menu22(note_assidu,note_projet,note_exam,note_assidu_bis,note_projet_bis,note_ds,cinetud,cinetud2,moy_asd,matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
        }
            }
int menu22(float note_assidu[100],float note_projet[100],float note_exam[100],float note_assidu_bis[100],float note_projet_bis[100],float note_ds[100],int cinetud[100],int cinetud2[100], float moy_asd[100],float moy_asd_bis[100],char matcin[100][8],char matnom[100][20],char matpnom[100][20], char matspec[100][9],int tab_grp[100], int tab_abs[100]){
    int ch2;
        printf("\n\n\t\t**************************** MENU 2 ****************************\n\n");
        printf("\tBienvenue dans la Partie 2: qui concerne les notes et les moyennes des etudiants:\n");

        printf("1.Ajouter Des Notes.\n");

        printf("2.Donner Les Moyennes Des Etudiants LNIG-BI/LNIG-BIS.\n");

        printf("3.Modifier la CIN d'un etudiant\n");

        printf("4.Trouver les etudiants ayant la meilleure note de projet toutes specialites confondues.\n");

        printf("5.Trouver l (es) etudiant(s) ayant la meilleure moyenne toutes specialites confondues\n");

        printf("6.Afficher la liste des etudiants qui n ont pas la moyenne dans XYZ.\n");

        printf("7.Afficher par groupe la liste des etudiants qui ont valide la mati\x8Are XYZ.\n");

        //printf("8.Déduire le groupe qui contient le moins d’étudiants ayant eu la moyenne pour la matière XYZ.\n");
        printf("0.Retour au menu principal.\n");
        printf("||------------------------------------------------------------------------------------------------||\n");
        printf("Veuillez faire un choix:\t");
        scanf("%d",&ch2);
        int e,j;
        switch (ch2){
        case 1:
            printf("Combien de note?\n");
            scanf("%i",&e);
            do{
            remplirnote(matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
            j++;
            }while(j<e);
            break;
        case 2:
            moy(moy_asd,moy_asd_bis,note_assidu,note_projet,note_exam,note_assidu_bis,note_projet_bis,note_ds,cinetud,cinetud2,matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
            //moy2(moy_asd,moy_asd_bis,note_assidu,note_projet,note_exam,note_assidu_bis,note_projet_bis,note_ds,cinetud,cinetud2,matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
            break;
             int i;
            int pos;
            int cin;
            int newcin;
            int r;
        case 3:

            printf("donnez la cin\n");
            scanf("%i",&cin);
            while (cinetud[i]!=0){
                if (cinetud[i]!=cin){
                        i++;
                }
                else{
                    pos=i;
                }
            }
            printf("Donnez la nouvelle CIN \t");
            scanf("%i",&newcin);
            cinetud[pos]=newcin;
            printf("La nouvelle cin est %i\n",cinetud[pos]);
            printf("retour au menu? 1=OUI 2=NON\n");
            scanf("%i",&r);
            if (r==1)
            menu22(note_assidu,note_projet,note_exam,note_assidu_bis,note_projet_bis,note_ds,cinetud,cinetud2,moy_asd,moy_asd_bis,matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
            break;
        case 4:
            maxproj(note_assidu,note_projet,note_exam,note_assidu_bis,note_projet_bis,note_ds,cinetud,cinetud2,moy_asd,moy_asd_bis,matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
            //maxproj2(note_projet_bis);
            break;
        case 5:
            moyy( moy_asd, moy_asd_bis,note_assidu,note_projet,note_exam,note_assidu_bis, note_projet_bis,note_ds, cinetud,cinetud2,matcin, matnom,matpnom,matspec,tab_grp, tab_abs);
            //moyy(note_assidu,note_projet,note_exam,note_assidu_bis,note_projet_bis,note_ds,cinetud,cinetud2,moy_asd,moy_asd_bis,matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
            break;
        case 6:
            nomoy(moy_asd,moy_asd_bis,note_assidu,note_projet,note_exam,note_assidu_bis,note_projet_bis,note_ds,cinetud,cinetud2,matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
            break;
        case 7:
            valider(moy_asd,moy_asd_bis,note_assidu,note_projet,note_exam,note_assidu_bis,note_projet_bis,note_ds,cinetud,cinetud2,matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
            break;
        case 0:
            menu(matcin,matnom,matpnom,matspec,tab_grp,tab_abs);
        break;
             }}

