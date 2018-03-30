from django.urls import path, re_path
from . import views

urlpatterns = [
    path('', views.index, name = 'index'), 
    
    # regular expression (regex) (?p<name>regex) there 
    # Basically refer to the regex by name
    # re_path function allows you to do regex 
    re_path('(?P<file_id>\d+)/', views.details, name = 'details'), 

]
