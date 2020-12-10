#!/usr/bin/env python
# coding: utf-8

# In[1]:


import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import datetime
get_ipython().run_line_magic('matplotlib', 'inline')


# In[2]:


# importing data
neowise_data = pd.read_json("../../data/json/neowise.json")

for index,row in neowise_data.iterrows():
    if("Comet"==row["orbit_class"]):
        continue
    elif("Comet" in row["orbit_class"]):
        neowise_data.drop(index, inplace = True)
neowise_data.head()


# In[3]:


# Preparing Data for Visualization
neowise_data['discovery_date'] = pd.to_datetime(neowise_data['discovery_date'])


# In[11]:


# Making Graph that will be displayed on Application Startup
plt.figure(figsize = (8,8))
fig, ax = plt.subplots()
ax.set_xlim([datetime.date(2010, 1, 1), datetime.date(2015, 12, 31)])

sns.set(style='darkgrid')

plt.title("Date vs Magnitude")
date_vs_magnitude = sns.scatterplot(x = "discovery_date", y = "h_mag", hue = "orbit_class", style = "pha",
                                    data = neowise_data)
date_vs_magnitude.set(xlabel = "Discovery Date", ylabel = "Apparent Magnitude")

#plt.savefig('../../data/default-images/date_vs_magnitude.png', dpi = 100)


# In[5]:


# Making First Selectable Graph
plt.figure(figsize = (8,8))

sns.set(style='darkgrid',)

plt.title("Perihelion vs Magnitude")
date_vs_magnitude = sns.scatterplot(x = "q_au_1", y = "h_mag", hue = "orbit_class", style="pha",data = neowise_data, 
                                    legend = "brief", palette = "hls")
date_vs_magnitude.set(xlabel = "Perihelion Distance (AU)", ylabel = "Apparent Magnitude")

plt.savefig('../../data/default-images/perihelion_vs_magnitude.png', dpi = 75)


# In[6]:


# Making Second Selectable Graph
plt.figure(figsize = (8,8))
fig, ax = plt.subplots()
ax.set_xlim([0,8])
sns.set(style='darkgrid',)
plt.title("Period vs Magnitude")
date_vs_magnitude = sns.scatterplot(x = "period_yr", y = "h_mag", hue = "orbit_class", data = neowise_data, 
                                    legend = "brief", style = 'pha',palette = "Paired")
date_vs_magnitude.set(xlabel = "Period (Yrs)", ylabel = "Apparent Magnitude")

plt.savefig('../../data/default-images/period_vs_magnitude.png', dpi = 100)


# In[7]:


for index,row in neowise_data.iterrows():
    if("Comet"==row["orbit_class"]):
        neowise_data.drop(index,inplace=True)


# In[8]:


# Making Third Selectable Graph
plt.figure(figsize = (8,8))
fig, ax = plt.subplots()
ax.set_ylim([0,1])
sns.set(style='darkgrid',)
plt.title("Perihelion vs MOID")
date_vs_magnitude = sns.scatterplot(x = "q_au_1", y = "moid_au", hue = "orbit_class", data = neowise_data, 
                                    legend = "brief", style = 'pha',palette = "rocket_r")
date_vs_magnitude.set(xlabel = "Perihelion Distance (AU)", ylabel = "Minimum orbit intersection distance (AU)")

plt.savefig('../../data/default-images/perihelion_vs_moid.png', dpi = 100)


# In[9]:


# Making Fourth Selectable Graph
plt.figure(figsize = (8,8))
fig, ax = plt.subplots()
sns.set(style='darkgrid',)
plt.title("Orbital Inclination vs Perihelion")
date_vs_magnitude = sns.scatterplot(x = "i_deg", y = "q_au_1", hue = "orbit_class", data = neowise_data, 
                                    legend = "brief", style = 'pha',palette = "Set2")
date_vs_magnitude.set(xlabel = "Orbital Inclination (Degrees)", ylabel = "Perihelion Distance (AU)")

plt.savefig('../../data/default-images/inclination_vs_perihelion.png', dpi = 100)


# In[10]:


# Making Final Selectable Graph
plt.figure(figsize = (8,8))
fig, ax = plt.subplots()
ax.set_ylim([0,10])
sns.set(style='darkgrid',)
plt.title("Perihelion vs Apohelion")
date_vs_magnitude = sns.scatterplot(x = "q_au_1", y = "q_au_2", hue = "orbit_class", data = neowise_data, 
                                    legend = "brief", style = 'pha',palette = "mako")
date_vs_magnitude.set(xlabel = "Perihelion Distance (AU)", ylabel = "Apohelion Distance (AU)")

plt.savefig('../../data/default-images/perihelion_vs_apohelion.png', dpi = 100)


# In[ ]:




