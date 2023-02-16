#!/usr/bin/python3
import cmd
import re
from models.base_model import BaseModel
from models import storage
from models.user import User
from models.state import State
from models.city import City
from models.amenity import Amenity
from models.place import Place
from models.review import Review

class HBNBCommand(cmd.Cmd):

    prompt = "(hbnb) "
    __classes = ["BaseModel",
                 "User",
                 "State",
                 "City",
                 "Amenity",
                 "Place",
                 "Review"
                 ]

    def do_quit(self, arg):
        """Quit command to exit the program
        """
        return True

    def do_EOF(self, arg):
        """EOF signal to exit the program
        """
        return True

    def emptyline(self):
        return

    def do_create(self, arg):
        args = arg.split()

        if len(args) == 0:
            print("** class name missing **")
        elif args[0] not in self.__classes:
            print("** class doesn't exist **")
        else:
            new_object = eval(f"{args[0]}")()
            print(new_object.id)
        storage.save()

    def do_show(self, arg):
        args = arg.split()

        if len(args) == 0:
            print("** class name missing **")
        elif args[0] not in self.__classes:
            print("** class doesn't exist **")
        elif len(args) == 1:
            print("** instance id missing **")
        elif f"{args[0]}.{args[1]}" not in storage.all():
            print("** no instance found **")
        else:
            print(storage.all()[f"{args[0]}.{args[1]}"])

    def do_destroy(self, arg):
        args = arg.split()

        if len(args) == 0:
            print("** class name missing **")
        elif args[0] not in self.__classes:
            print("** class doesn't exist **")
        elif len(args) == 1:
            print("** instance id missing **")
        elif f"{args[0]}.{args[1]}" not in storage.all():
            print("** no instance found **")
        else:
            del storage.all()[f"{args[0]}.{args[1]}"]
        storage.save()

    def do_all(self, arg):
        args = arg.split()

        if len(args) == 0:
            print([str(value) for value in storage.all().values()])
        elif args[0] not in self.__classes:
            print("** class doesn't exist **")
        else:
            print([str(v) for k, v in storage.all().items() if k.startswith(args[0])])

    def do_update(self, arg):
        args = arg.split()

        if len(args) == 0:
            print("** class name missing **")
        elif args[0] not in self.__classes:
            print("** class doesn't exist **")
        elif len(args) == 1:
            print("** instance id missing **")
        elif f"{args[0]}.{args[1]}" not in storage.all():
            print("** no instance found **")
        elif len(args) == 2:
            print("** attribute name missing **")
        elif len(args) == 3:
            print("** value missing **")
        else:
            obj_class = args[0]
            obj_id = args[1]
            obj_key = obj_class + "." + obj_id
            obj = storage.all()[obj_key]

            if type(eval(argl[2])) == dict:
                for k, v in eval(argl[2]).items():    
                    attr_name = k
                    attr_value = v

                    if attr_value[0] == '"':
                        attr_value = attr_value[1:-1]

                    if hasattr(obj, attr_name):
                        type_ = type(getattr(obj, attr_name))
                        if type_ in [str, float, int]:
                            attr_value = type_(attr_value)
                            setattr(obj, attr_name, attr_value)
                    else:
                        setattr(obj, attr_name, attr_value)
            
            else:
                attr_name = args[2]
                attr_value = args[3]

                if attr_value[0] == '"':
                    attr_value = attr_value[1:-1]

                if hasattr(obj, attr_name):
                    type_ = type(getattr(obj, attr_name))
                    if type_ in [str, float, int]:
                        attr_value = type_(attr_value)
                        setattr(obj, attr_name, attr_value)
                else:
                    setattr(obj, attr_name, attr_value)
            storage.save()

    def default(self, arg):
        args = arg.split('.')
        if args[0] in self.__classes:
            if args[1] == "all()":
                self.do_all(args[0])
            elif args[1] == "count()":
                list_ = [v for k, v in storage.all().items() if k.startswith(args[0])]
                print(len(list_))
            elif args[1].startswith("show"):
                id_ = args[1].split('"')[1]
                self.do_show(f"{args[0]} {id_}")
            elif args[1].startswith("destroy"):
                id_ = args[1].split('"')[1]
                self.do_destroy(f"{args[0]} {id_}")
            elif args[1].startswith("update"):
                if "{" not in args[1]:
                    split_ = re.split('"update"|", "|\"', args[1])
                    id_ = split_[1]
                    attr_name = split_[2]
                    attr_value = split_[4]
                    self.do_update(f'{args[0]} {id_} {attr_name} "{attr_value}"')
                else:
                    split_ =  re.split('{', args[1])
                    split_ =  re.split('}', split_[1])
                    self.do_update(f'{args[0]}' + '{' + f'{split_}' + '}')
                storage.save()

if __name__ == '__main__':
    HBNBCommand().cmdloop()
