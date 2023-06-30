#include"tulippch.h"
#include "OpenGLVertexArray.h"

#include <glad/glad.h>


namespace Tulip 
{
    static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
    {
        switch (type)
        {
        case Tulip::ShaderDataType::Float:     return GL_FLOAT;
        case Tulip::ShaderDataType::Float2:    return GL_FLOAT;
        case Tulip::ShaderDataType::Float3:    return GL_FLOAT;
        case Tulip::ShaderDataType::Float4:    return GL_FLOAT;
        case Tulip::ShaderDataType::Mat3:      return GL_FLOAT;
        case Tulip::ShaderDataType::Mat4:      return GL_FLOAT;
        case Tulip::ShaderDataType::Int:       return GL_FLOAT;
        case Tulip::ShaderDataType::Int2:      return GL_FLOAT;
        case Tulip::ShaderDataType::Int3:      return GL_FLOAT;
        case Tulip::ShaderDataType::Int4:      return GL_FLOAT;
        case Tulip::ShaderDataType::Bool:      return GL_FLOAT;
        }

        TULIP_CORE_ASSERT(false, "Unknown ShadeDataType.");
        return 0;
    }

    OpenGLVertexArray::OpenGLVertexArray()
    {
        glCreateVertexArrays(1, &m_RendererID);
    }

    OpenGLVertexArray::~OpenGLVertexArray()
    {
        glDeleteVertexArrays(1, &m_RendererID);
    }

    void OpenGLVertexArray::Bind() const
    {
        glBindVertexArray(m_RendererID);
    }

    void OpenGLVertexArray::UnBind() const
    {
        glBindVertexArray(0);
    }

    void OpenGLVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer)
    {
        TULIP_CORE_ASSERT(vertexBuffer->GetLayout().GetElements().size(), "vertex Buffer has no layout.");

        glBindVertexArray(m_RendererID);
        vertexBuffer->Bind();

        uint32_t index = 0;
        const auto& layout = vertexBuffer->GetLayout();
        for (const auto& element : layout)
        {
            glEnableVertexAttribArray(index);
            glVertexAttribPointer(index,
                element.GetComponentCount(),
                ShaderDataTypeToOpenGLBaseType(element.Type),
                element.Normalized ? GL_TRUE : GL_FALSE,
                layout.GetStride(),
                (const void*)element.Offset);
            index++;
        }

        m_VertexBuffers.push_back(vertexBuffer);
    }

    void OpenGLVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer)
    {
        glBindVertexArray(m_RendererID);
        indexBuffer->Bind();

        m_IndexBuffer = indexBuffer;
    }
}