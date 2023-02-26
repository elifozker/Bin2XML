#include <stdio.h>
#include <stdlib.h> 

struct record {
 char name[64]; //utf1s6
 char surname[32]; //utf8 
 char gender; 
 char email[32];
 char phone_number[16];
 char address[32];
 char level_of_education[8];
 unsigned int income_level; // given little-endian
 unsigned int expenditure; // given big-endian 
 char currency_unit[16];
 char currentMood[32];
 float height;
 unsigned int weight;

}rec;

void createXMLFile(FILE *binaryFile,char *CreatingXml){
    FILE *xmlFile;
    xmlFile = fopen(CreatingXml,"w");
    fprintf(xmlFile,"<records>\n"); 
    int i= 1;
    fread(&rec, sizeof(rec), 1, binaryFile);
    while(i != 51) { 
        fread(&rec, sizeof(rec), 1, binaryFile);
        fprintf(xmlFile,"\t<row id=\"%d\">\n",i);
        fprintf(xmlFile,"\t\t<name>%s</name>\n",rec.name);
        fprintf(xmlFile,"\t\t<surname>%s</surname>\n",rec.surname);
        fprintf(xmlFile,"\t\t<gender>%c</gender>\n",rec.gender);
        fprintf(xmlFile,"\t\t<email>%s</email>\n",rec.email);
        fprintf(xmlFile,"\t\t<phone_number>%s</phone_number>\n",rec.phone_number);
        fprintf(xmlFile,"\t\t<address>%s</address>\n",rec.address);
        fprintf(xmlFile,"\t\t<level_of_education>%s</level_of_education>\n",rec.level_of_education);
        fprintf(xmlFile,"\t\t<income_level>%u</income_level>\n",rec.income_level);
        fprintf(xmlFile,"\t\t<expenditure>%u</expenditure>\n",rec.expenditure);
        fprintf(xmlFile,"\t\t<currency_unit>%s</currency_unit>\n",rec.currency_unit);
        fprintf(xmlFile,"\t\t<currentMood>%s</currentMood>\n",rec.currentMood);
        fprintf(xmlFile,"\t\t<height>%f</height>\n",rec.height);
        fprintf(xmlFile,"\t\t<weight>%u</weight>\n",rec.weight);
        fprintf(xmlFile,"\t</row>\n");      
        i++;
    }   
    fprintf(xmlFile,"</records>\n");
    fclose(binaryFile);
    fclose(xmlFile);

}
void binaryFileReader(char *binaryFile,char *CreatingXml){
    FILE *bf;
    bf = fopen(binaryFile, "rb");
    if(bf == NULL)
    {
        printf("Error opening file!");
        exit(EXIT_FAILURE);
    }
    createXMLFile(bf,CreatingXml);
    fclose(bf);
}
int main(int argc, char *argv[] ){
   
    if(argc == 3){      
        char *binaryFile = argv[1];
        char *CreatingXml = argv[2];
        printf("XML is creating...\n");       
        binaryFileReader(binaryFile, CreatingXml); 
    }
    else{ 
        printf("Please enter in this format --> ./Bin2XML records.dat records.xml\n");
    }
   
}