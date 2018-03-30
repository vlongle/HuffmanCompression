from django.http import Http404
from django.shortcuts import render
from .models import compress_file
# Create your views here.

def index(request):
    all_files = compress_file.objects.all() # fetch from database
    
    # info for template, dict data struct
    # context must be a dict
    context = {'all_files' : all_files,}
    
    # rendering html with context data 
    return render(request, 'compression/index.html', context)


def details(request, file_id):
    all_files = compress_file.objects.all()
    validation = int(file_id) <= len(all_files) # len(all_files) gives the highest id possible in database now
    if validation:
        return HttpResponse("<h1> You're user " + str(file_id) + " </h1>")
    else:
        raise Http404("Invalid file id")