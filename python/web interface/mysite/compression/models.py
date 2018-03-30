from django.db import models

# Create your models here.

class compress_file(models.Model): # class inheritance
    name = models.CharField(max_length = 250)
    options = models.CharField(max_length = 250)
#    txt_file = models.FileField() # upload the text file here! 
    
    def __str__(self):
        return self.name + " >> " + self.options