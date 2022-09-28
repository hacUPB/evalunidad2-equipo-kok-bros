#include "eventList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

EventList *CreateEventList(void)
{
    EventList *eventList = malloc(sizeof(EventList));
    eventList->isEmpty = 1;
    eventList->head = 0;
    eventList->last = 0;
    
    return eventList;
}


Event *SearchEvent(EventList *this, char *name)
{
    Event *actualEvent = this->head;
    if (this->isEmpty == 0)
    {
        while (actualEvent != NULL)
        {
            if (strcmp(name, actualEvent->eventName)==0)
            return actualEvent;
            actualEvent = actualEvent->next;
        }
    }
    actualEvent = NULL;
    return actualEvent;
}

void AddEvent(EventList *this, Event *event)
{
    Event *actualEvent = this->head;
    while (actualEvent != NULL)
    {
        if(strcmp(event->eventName, actualEvent->eventName) == 0)
        return;

        actualEvent = actualEvent->next;
    }
    
   if(this->isEmpty == 0)
   {
        this->last->next = event;
        this->last=event;
   }
   else
   {
       this->head = event;
       this->last = event;
       this->isEmpty = 0;    
   }
}

void RemoveEvent(EventList *this, char *name)
{
   
}

void ListEvents(EventList *this)
{
   
}

void DestroyEventList(EventList *this)
{
    free(this->isEmpty);
}