using System;

namespace CV10 {
    static class ShapeFactory {
        public static IMesh shape_factory(string shape, double edge) {
            Type myClassType = Type.GetType(String.Format("{0}.{1}", "CV10", @shape));
            object instance = myClassType == null ? null : Activator.CreateInstance(myClassType);
            if (instance == null) return null;
            Shape transponed_object = instance as Shape;
            transponed_object.setEdgeLength(edge);
            return transponed_object;
        }
    }
}
