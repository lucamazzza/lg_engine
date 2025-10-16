#pragma once

#include <glm/glm.hpp>
#include <memory>
#include <vector>

#include "Common.h"

class LIB_API Object {
    Object();
    Object(const std::string name);
    void set_name(const std::string name);
    void add_child(const std::shared_ptr<Object> child);
    int get_id() const;
    std::string get_name() const;
    virtual glm::mat4 get_local_matrix() const;
    virtual int get_priority() const;
    std::vector<std::shared_ptr<Object>> get_children() const;
    virtual void render(const glm::mat4 world_matrix
#ifdef _APPLE
            , id<MTLRenderCommandEncoder> encoder = nil
#endif
            ) const = 0;
protected:
    std::vector<std::shared_ptr<Object>> children;
private:
    static int next_id;
    int id;
    std::string name;
};

